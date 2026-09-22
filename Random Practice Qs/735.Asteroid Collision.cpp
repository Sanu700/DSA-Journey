class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int x : asteroids){
            bool alive = true;
        while(alive && !st.empty() && st.top() > 0 && x < 0){
           if(abs(x) > st.top()){
            st.pop();
           }
           else if(abs(x) == st.top()){
            st.pop();
            alive = false;
           }
           else {
            alive = false;
           }
           
        }
        if(alive) st.push(x);
        
        
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};