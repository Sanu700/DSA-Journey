class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        unordered_set<string> words(wordList.begin(), wordList.end());

     
        if(!words.count(endWord))
            return 0;

        queue<string> q;
        q.push(beginWord);

        int steps = 1;

        while(!q.empty()) {

            int size = q.size();

            while(size--) {

                string word = q.front();
                q.pop();

              
                for(int i = 0; i < word.size(); i++) {

                    char original = word[i];

                    for(char ch = 'a'; ch <= 'z'; ch++) {

                        if(ch == original)
                            continue;

                        word[i] = ch;

                        if(words.count(word)) {

                            if(word == endWord)
                                return steps + 1;

                            q.push(word);

                          
                            words.erase(word);
                        }
                    }

                    word[i] = original;
                }
            }

            steps++;
        }

        return 0;
    }
};