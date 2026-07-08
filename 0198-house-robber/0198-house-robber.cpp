class Solution {
public:
    vector<int> value;
    int solve(int i, vector<int>& nums){
    if(i >= nums.size()) return 0;         
    if(value[i] != -1) return value[i];
    
    int include = nums[i] + solve(i+2, nums);
    int exclude = solve(i+1, nums);
    
    value[i] = max(include, exclude);     
    return value[i];
}

    int rob(vector<int>& nums) {
        value.assign(nums.size(),-1);
        int ans= 0 ; 
        ans = max(ans,solve(0,nums));
        return ans;
    }
};