class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        int n = classroom.size();
        int m = classroom[0].size();

        int sr = 0, sc = 0;
        int k = 0;

        vector<vector<int>> id(n, vector<int>(m, -1));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    id[i][j] = k++;
                }
            }
        }

        int fullMask = (1 << k) - 1;

        if (k == 0)
            return 0;

        vector<vector<vector<int>>> best(
            1 << k,
            vector<vector<int>>(
                n,
                vector<int>(m, -1)
            )
        );

        queue<tuple<int, int, int, int, int>> q;

        q.push({sr, sc, energy, 0, 0});
        best[0][sr][sc] = energy;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            auto [r, c, currEnergy, mask, moves] = q.front();
            q.pop();

            if (mask == fullMask)
                return moves;
            if (currEnergy == 0)
                continue;

            for (int d = 0; d < 4; d++) {

                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr < 0 || nr >= n ||
                    nc < 0 || nc >= m)
                    continue;

                if (classroom[nr][nc] == 'X')
                    continue;

                int newEnergy = currEnergy - 1;
                int newMask = mask;
                if (classroom[nr][nc] == 'R') {
                    newEnergy = energy;
                }
                if (classroom[nr][nc] == 'L') {
                    int idx = id[nr][nc];
                    newMask |= (1 << idx);
                }
                if (best[newMask][nr][nc] >= newEnergy)
                    continue;

                best[newMask][nr][nc] = newEnergy;

                q.push({
                    nr,
                    nc,
                    newEnergy,
                    newMask,
                    moves + 1
                });
            }
        }

        return -1;
    }
};