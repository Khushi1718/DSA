class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGCD(n);
        int maxt = 0;
        for(int i = 0 ; i <n ; i ++){
            maxt = max(maxt,nums[i]);
            prefixGCD[i] = gcd (maxt, nums[i]);
        }
        sort(prefixGCD.begin(),prefixGCD.end());
        long long ans = 0 ;
        int left = 0 ;
        int right =n-1;
        while(left<right){
            ans+=gcd(prefixGCD[left],prefixGCD[right]);
            left++;
            right--;
        }
        return ans;
    }
};