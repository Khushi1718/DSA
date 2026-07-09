class Solution {
public:
   bool dfs(vector<vector<int>>& adj, vector<int>& vis, int s, int d){
    if(s==d)
        return true;

    vis[s]=1;

    for(int x:adj[s]){
        if(vis[x]==-1){
            if(dfs(adj,vis,x,d))
                return true;
        }
    }
    return false;
}
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int> vis(n,-1);
        return dfs(adj,vis,source,destination);
    }
};