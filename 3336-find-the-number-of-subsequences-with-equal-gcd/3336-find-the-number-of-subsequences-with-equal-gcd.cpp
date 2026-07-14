class Solution {
public:
    static const int MOD = 1e9 + 7;
    int n;
    int mx;
    int dp[205][201][201];

    int solve(int i, int g1, int g2, vector<int>& nums) {

        if (i == n)
            return (g1 == g2 && g1 != 0);

        int &ans = dp[i][g1][g2];
        if (ans != -1)
            return ans;

        long long res = 0;
        res += solve(i + 1, gcd(g1, nums[i]), g2, nums);
        res += solve(i + 1, g1, gcd(g2, nums[i]), nums);
        res += solve(i + 1, g1, g2, nums);

        return ans = res % MOD;
    }

    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, nums);
    }
};