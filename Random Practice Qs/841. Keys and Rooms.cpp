class Solution {
public:
    vector<bool> vis;
    void dfs(int node,vector<vector<int>>& rooms){
        vis[node] = true;
        for(int n : rooms[node]){
            if(!vis[n]){
                dfs(n,rooms);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vis.resize(n,false);
        dfs(0,rooms);
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                return false;
            }
        }
        return true;
    }
};

