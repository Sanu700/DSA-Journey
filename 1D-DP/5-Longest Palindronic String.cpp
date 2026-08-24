class Solution {
public:

    string longestPalindrome(string s) {

        int n = s.size();

        vector<bool> dp(n, false);

        int start = 0;
        int maxLen = 1;

        for(int l = n - 1; l >= 0; l--) {

            bool prev = false;

            for(int r = l; r < n; r++) {

                bool temp = dp[r];

                if(s[l] == s[r] &&
                   (r - l <= 2 || prev)) {

                    dp[r] = true;

                    if(r - l + 1 > maxLen) {
                        start = l;
                        maxLen = r - l + 1;
                    }
                }
                else {
                    dp[r] = false;
                }

                prev = temp;
            }
        }

        return s.substr(start, maxLen);
    }
};