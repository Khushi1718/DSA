class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0 ; 
        int prefix = 0 ;
        unordered_map<int,int> mp;
        mp[0]=1;
        for(int n : nums){
            prefix+=n ;
            if(mp.find(prefix - k) != mp.end()){
                count+=mp[prefix-k];
            }
            mp[prefix]++;
        }
        return count;
    }
};