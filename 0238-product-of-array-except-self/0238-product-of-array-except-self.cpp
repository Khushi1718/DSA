class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int curr = 1 ;
        int n = nums.size();
        vector<int> prefix(n,1);
        vector<int>suffix(n,1);
        for(int i=0;i<n;i++){
            prefix[i] = curr;
            curr*=nums[i];  
        }
        curr = 1;
        for(int i = n-1;i>=0;i--){
            suffix[i]=curr*prefix[i]; 
            curr*=nums[i];
        }
        return suffix;
    }
};