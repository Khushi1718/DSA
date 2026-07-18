class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j) {
        vis[i][j] = 1;
        int area = 1;
        if (i + 1 < grid.size() && grid[i + 1][j] == 1 && vis[i + 1][j] == -1) {
            area += dfs(grid, vis, i + 1, j);
        }
        if (i - 1 >= 0 && grid[i - 1][j] == 1 && vis[i - 1][j] == -1) {
            area += dfs(grid, vis, i - 1, j);
        }
        if (j + 1 < grid[0].size() && grid[i][j + 1] == 1 && vis[i][j + 1] == -1) {
            area += dfs(grid, vis, i, j + 1);
        }
        if (j - 1 >= 0 && grid[i][j - 1] == 1 && vis[i][j - 1] == -1) {
            area += dfs(grid, vis, i, j - 1);
        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, -1));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && vis[i][j] == -1) {
                    ans = max(ans, dfs(grid, vis, i, j));
                }
            }
        }
        return ans;
    }
};