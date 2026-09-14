class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0;
        int left = 0 ;
        int curr=0;
        for(int right =0;right<nums.size();right++){
            if(nums[right]==0){
                curr++;
            }
            while(curr>k){
                if(nums[left]==0){
                    curr--;
                }
                left++;
            }
            ans= max(ans,right-left+1);
        }
        return ans;
    }
};