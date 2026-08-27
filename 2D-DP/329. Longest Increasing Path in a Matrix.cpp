class Solution {
public:
    int dfs(int r, int c, vector<vector<int>>& matrix,
            vector<vector<int>>& dp) {

        if(dp[r][c] != 0)
            return dp[r][c];

        int m = matrix.size();
        int n = matrix[0].size();

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        dp[r][c] = 1;

        for(int k = 0; k < 4; k++) {

            int nr = r + dr[k];
            int nc = c + dc[k];

            if(nr >= 0 && nr < m &&
               nc >= 0 && nc < n &&
               matrix[nr][nc] > matrix[r][c]) {

                dp[r][c] = max(dp[r][c],
                               1 + dfs(nr, nc, matrix, dp));
            }
        }

        return dp[r][c];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        int ans = 0;

        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {

                ans = max(ans, dfs(r, c, matrix, dp));
            }
        }

        return ans;
    }
};