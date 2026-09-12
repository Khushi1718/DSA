class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int count = 0 ;
        int odd = 0 ;
        mp[0]=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if (nums[i]%2 !=0){
                odd++;
            }
            int need = odd - k;
            if(mp.find(need) != mp.end()){
                count+=mp[need];
            }
            mp[odd]++;
        }
        return count;

    }
};