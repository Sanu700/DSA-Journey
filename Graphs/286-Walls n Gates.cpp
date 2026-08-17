class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int,int>> q;

        // Put all treasures into the queue
        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {

                if(grid[r][c] == 0)
                    q.push({r, c});
            }
        }

        vector<pair<int,int>> directions = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };

        // Multi-source BFS
        while(!q.empty()) {

            auto [r, c] = q.front();
            q.pop();

            for(auto [dr, dc] : directions) {

                int nr = r + dr;
                int nc = c + dc;

                // Check boundaries and unvisited land
                if(nr >= 0 && nr < rows &&
                   nc >= 0 && nc < cols &&
                   grid[nr][nc] == INT_MAX) {

                    grid[nr][nc] = grid[r][c] + 1;

                    q.push({nr, nc});
                }
            }
        }
    }
};