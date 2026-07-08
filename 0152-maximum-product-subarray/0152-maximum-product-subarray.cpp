class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProd = nums[0];
        int minProd = nums[0];
        int ans = nums[0];

        for (int i = 1; i < n; i++) {
            int curr = nums[i];
            int tempMax = maxProd;
            maxProd = max({curr, curr * maxProd, curr * minProd});
            minProd = min({curr, curr * tempMax, curr * minProd});

            ans = max(ans, maxProd);
        }

        return ans;
    }
};