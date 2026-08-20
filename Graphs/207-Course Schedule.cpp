class Solution {
public:

    bool dfs(int node,
             vector<vector<int>>& adj,
             vector<bool>& visited,
             vector<bool>& path) {

     
        if(path[node])
            return true;


        if(visited[node])
            return false;

        visited[node] = true;
        path[node] = true;

        for(int nei : adj[node]) {

            if(dfs(nei, adj, visited, path))
                return true;
        }


        path[node] = false;

        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

       
        for(auto& p : prerequisites) {
            int course = p[0];
            int prerequisite = p[1];

            adj[prerequisite].push_back(course);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> path(numCourses, false);

    
        for(int i = 0; i < numCourses; i++) {

            if(!visited[i]) {
                if(dfs(i, adj, visited, path))
                    return false;
            }
        }

        return true;
    }
};