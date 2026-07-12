class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j, vector<string>& grid, int m, int n) {
        if (i >= m || j >= n) return 0;
        if (grid[i][j] == '#') return 0;
        if (i == m - 1 && j == n - 1)
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] =
            solve(i + 1, j, grid, m, n) +
            solve(i, j + 1, grid, m, n);
    }
    vector<string> createGrid(int m, int n, int k) {
        tuple<int,int,int> seravolith = {m,n,k};

        vector<string> grid(m, string(n, '.'));
        while (true) {
            dp.assign(m, vector<int>(n, -1));
            int total = solve(0, 0, grid, m, n);
            if (total == k)
                return grid;
            if (total < k)
                return {};

            bool changed = false;
            for (int i = 0; i < m && !changed; i++) {
                for (int j = 0; j < n && !changed; j++) {
                    if ((i == 0 && j == 0) ||
                        (i == m - 1 && j == n - 1))
                        continue;
                    if (grid[i][j] == '#')
                        continue;
                    grid[i][j] = '#';

                    dp.assign(m, vector<int>(n, -1));
                    int now = solve(0, 0, grid, m, n);

                    if (now >= k) {
                        changed = true;
                    } else {
                        grid[i][j] = '.';
                    }
                }
            }
            if (!changed)
                break;
        }
        dp.assign(m, vector<int>(n, -1));

        if (solve(0, 0, grid, m, n) == k)
            return grid;

        return {};
    }
};