class Solution {
public:
    int countSubstrings(string s) {

        int n = s.size();

        vector<bool> dp(n, false);

        int count = 0;

        for(int l = n - 1; l >= 0; l--) {

            bool prev = false;

            for(int r = l; r < n; r++) {

                bool temp = dp[r];

                if(s[l] == s[r] &&
                   (r - l <= 2 || prev)) {

                    dp[r] = true;
                    count++;
                }
                else {
                    dp[r] = false;
                }

                prev = temp;
            }
        }

        return count;
    }
};