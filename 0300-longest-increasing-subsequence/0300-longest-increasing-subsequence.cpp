class Solution {
public:
    vector<int> temp;
    int lengthFrom(int i, vector<int>& nums) {
        if (temp[i] != -1) return temp[i]; 
        int best = 1; 
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] > nums[i]) {
                best = max(best, 1 + lengthFrom(j, nums));
            }
        }
        temp[i] = best; 
        return best;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        temp.assign(n, -1);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, lengthFrom(i, nums));
        }
        return ans;
    }
};