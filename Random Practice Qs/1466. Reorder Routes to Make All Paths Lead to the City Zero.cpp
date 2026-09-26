class Solution {
public:
    void dfs(int node, vector<vector<pair<int,int>>>& adj,
             vector<bool>& visited, int& count) {

        visited[node] = true;

        for (auto [next, direction] : adj[node]) {

            if (!visited[next]) {

                if (direction == 1) {
                    count++;
                }

                dfs(next, adj, visited, count);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {

        vector<vector<pair<int,int>>> adj(n);

        for (auto& road : connections) {
            int u = road[0];
            int v = road[1];

            adj[u].push_back({v, 1});
            adj[v].push_back({u, 0});
        }

        vector<bool> visited(n, false);
        int count = 0;

        dfs(0, adj, visited, count);

        return count;
    }
};