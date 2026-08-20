class Solution {
public:

    bool dfs(int node,
             vector<vector<int>>& adj,
             vector<bool>& visited,
             vector<bool>& path,
             vector<int>& ans) {

        // Cycle detected
        if(path[node])
            return false;

        // Already processed
        if(visited[node])
            return true;

        visited[node] = true;
        path[node] = true;

        for(int nei : adj[node]) {

            if(!dfs(nei, adj, visited, path, ans))
                return false;
        }

        // Finished exploring this node
        path[node] = false;

        // Add after processing neighbours
        ans.push_back(node);

        return true;
    }

    vector<int> findOrder(int numCourses,
                           vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        // Build graph:
        // prerequisite → course
        for(auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> path(numCourses, false);

        vector<int> ans;

        // DFS from every course
        for(int i = 0; i < numCourses; i++) {

            if(!visited[i]) {

                if(!dfs(i, adj, visited, path, ans))
                    return {};
            }
        }

        // DFS gives reverse topological order
        reverse(ans.begin(), ans.end());

        return ans;
    }
};