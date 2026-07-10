class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                     vector<vector<int>>& queries) {

        vector<pair<int,int>> arr;

        for (int i = 0; i < n; i++)
            arr.push_back({nums[i], i});

        sort(arr.begin(), arr.end());

        // original index -> sorted position
        vector<int> pos(n);

        for (int i = 0; i < n; i++)
            pos[arr[i].second] = i;

        // next[i] = farthest position reachable in one edge
        vector<int> nxt(n);

        int j = 0;

        for (int i = 0; i < n; i++) {

            while (j + 1 < n &&
                   arr[j + 1].first - arr[i].first <= maxDiff)
                j++;

            nxt[i] = j;
        }

        const int LOG = 18;

        vector<vector<int>> up(LOG, vector<int>(n));

        for (int i = 0; i < n; i++)
            up[0][i] = nxt[i];

        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                up[k][i] = up[k - 1][up[k - 1][i]];
            }
        }

        vector<int> ans;

        for (auto &q : queries) {

            int l = pos[q[0]];
            int r = pos[q[1]];

            if (l > r)
                swap(l, r);

            if (l == r) {
                ans.push_back(0);
                continue;
            }

            // unreachable
            if (up[LOG - 1][l] < r) {
                ans.push_back(-1);
                continue;
            }

            int jumps = 0;
            int cur = l;

            for (int k = LOG - 1; k >= 0; k--) {

                if (up[k][cur] < r) {
                    jumps += (1 << k);
                    cur = up[k][cur];
                }
            }

            ans.push_back(jumps + 1);
        }

        return ans;
    }
};