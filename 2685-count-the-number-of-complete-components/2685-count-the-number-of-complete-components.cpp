class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int count = 0;
        vector<int> vis(n,0);
        vector<vector<int>>adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                queue<int> q;
                q.push(i);
                vis[i]=1;
               vector<int> component;
               while(!q.empty()){
                   int node = q.front();
                   q.pop();
                   component.push_back(node);

                   for(auto nbr : adj[node]){
                      if(!vis[nbr]){
                         vis[nbr]=1;
                         q.push(nbr);
                     }
                    }
                }
                int nodes = component.size();
                int degreeSum = 0;
                for(auto node : component)
                    degreeSum += adj[node].size();
                    int edge = degreeSum / 2;
                    if(edge == nodes*(nodes-1)/2)
                    count++;
                }
    }
    return count;
}};