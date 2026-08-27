class Solution {
public:
    int maxCoins(vector<int>& nums) {

        int n = nums.size();

        // Add virtual balloons with value 1 at both ends
        vector<int> a(n + 2, 1);

        for(int i = 0; i < n; i++) {
            a[i + 1] = nums[i];
        }

        // dp[l][r] = maximum coins from bursting balloons l...r
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        // Length of interval
        for(int len = 1; len <= n; len++) {

            for(int l = 1; l + len - 1 <= n; l++) {

                int r = l + len - 1;

                // Choose k as the LAST balloon to burst
                for(int k = l; k <= r; k++) {

                    int coins = a[l - 1] * a[k] * a[r + 1];

                    coins += dp[l][k - 1];
                    coins += dp[k + 1][r];

                    dp[l][r] = max(dp[l][r], coins);
                }
            }
        }

        return dp[1][n];
    }
};