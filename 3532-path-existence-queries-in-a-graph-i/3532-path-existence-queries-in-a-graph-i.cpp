class Solution {
public:
    vector<int> parent, sz;
    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v)
            return;

        if (sz[u] < sz[v])
            swap(u, v);

        parent[v] = u;
        sz[u] += sz[v];
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums,
                                      int maxDiff,
                                      vector<vector<int>>& queries) {

        parent.resize(n);
        sz.assign(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] <= maxDiff)
                Union(i, i - 1);
        }
        vector<bool> ans;
        for (auto &q : queries) {
            ans.push_back(find(q[0]) == find(q[1]));
        }

        return ans;
    }
};