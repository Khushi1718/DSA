class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> set;
        int left = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (set.find(nums[i]) != set.end()) {
                return true;
            }

            set.insert(nums[i]);
            if (i - left >= k) {
                set.erase(nums[left]);
                left++;
            }
        }

        return false;
    }
};