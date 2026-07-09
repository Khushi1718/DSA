class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int i, int j){
        vis[i][j] = 1;
        int m = grid.size();
        int n = grid[0].size();

        if(i-1 >= 0 && grid[i-1][j] == '1' && vis[i-1][j] == 0)
            dfs(grid, vis, i-1, j);

        if(i+1 < m && grid[i+1][j] == '1' && vis[i+1][j] == 0)
            dfs(grid, vis, i+1, j);

        if(j-1 >= 0 && grid[i][j-1] == '1' && vis[i][j-1] == 0)
            dfs(grid, vis, i, j-1);

        if(j+1 < n && grid[i][j+1] == '1' && vis[i][j+1] == 0)
            dfs(grid, vis, i, j+1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1' && vis[i][j] == 0){
                    count++;
                    dfs(grid, vis, i, j);
                }
            }
        }
        return count;
    }
};