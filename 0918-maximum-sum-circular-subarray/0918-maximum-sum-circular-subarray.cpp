// class Solution {
// public:
//     int maxSubarraySumCircular(vector<int>& nums) {
//         int ans=nums[0];
//         for(int i=0;i<nums.size();i++){
//             int size = 1 ; 
//             int currsum = nums[i];
//             int idx=i;
//             while(size<nums.size()){
//                 idx=(idx+1)%nums.size();
//                 currsum= max(nums[idx],currsum+nums[idx]);
//                 ans = max(ans,currsum);
//                 size++;
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        int currMax = nums[0], maxSum = nums[0];
        int currMin = nums[0], minSum = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            total += nums[i];
        }

        for (int i = 1; i < nums.size(); i++) {
            currMax = max(nums[i], currMax + nums[i]);
            maxSum = max(maxSum, currMax);

            currMin = min(nums[i], currMin + nums[i]);
            minSum = min(minSum, currMin);
        }

        if (maxSum < 0) return maxSum; // all negative — see edge case below
        return max(maxSum, total - minSum);
    }
};