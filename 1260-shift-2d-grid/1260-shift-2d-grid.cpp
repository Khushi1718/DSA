class Solution {
public:
    void rotate(vector<vector<int>>& grid,vector<vector<int>>& ans, int m , int n ){

        ans[0][0]= grid[m-1][n-1];
        for(int i = 0 ; i < m-1 ;i++){
            ans[i+1][0]= grid[i][n - 1];
        }
        for(int i = 0 ; i <m ; i ++){
            for(int j = 1 ; j <n;j++){
                ans[i][j]= grid[i][j-1];
            }
        }
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if (k==0) return grid;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans (m , vector<int>(n,0));
        for(int i = 0 ;i <k ;i++){
            rotate(grid,ans,m,n);
            grid = ans;
        }
        
        return ans;
    }
};