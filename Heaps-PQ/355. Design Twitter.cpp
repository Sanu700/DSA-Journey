class Twitter {
    struct Tweet {
        int id;
        int time;

        Tweet(int id, int time) : id(id), time(time) {}
    };

    unordered_map<int, vector<Tweet>> tweets;
    unordered_map<int, unordered_set<int>> following;

    int time = 0;

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({tweetId, time++});
    }

    vector<int> getNewsFeed(int userId) {

        // {time, userId, index of tweet}
        priority_queue<tuple<int, int, int>> pq;

        // User's own tweets
        if(!tweets[userId].empty()) {
            int i = tweets[userId].size() - 1;
            pq.push({tweets[userId][i].time, userId, i});
        }

        // Followees' latest tweets
        for(int followee : following[userId]) {
            if(!tweets[followee].empty()) {
                int i = tweets[followee].size() - 1;
                pq.push({tweets[followee][i].time, followee, i});
            }
        }

        vector<int> ans;

        // Get 10 most recent tweets
        while(!pq.empty() && ans.size() < 10) {

            auto [time, userId, idx] = pq.top();
            pq.pop();

            ans.push_back(tweets[userId][idx].id);

            // Push previous tweet from same user
            if(idx > 0) {
                pq.push({
                    tweets[userId][idx - 1].time,
                    userId,
                    idx - 1
                });
            }
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        if(followerId != followeeId)
            following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};