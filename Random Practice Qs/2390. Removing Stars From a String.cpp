class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for(char c : s){
            if(c == '*'){
                st.pop(c);

            }
            else st.push(c);
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};



