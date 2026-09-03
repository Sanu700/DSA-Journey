class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long long, int>> pq;

        for(int i = 0;i<points.size();i++){
            long long x = points[i][0];
            long long y = points[0][i];

            long long dist = x*x + y*y;

            pq.push(dist,i);

            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;


        
    }
};

