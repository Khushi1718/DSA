class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mine = INT_MAX;
        int maxe = INT_MIN;
        for(int x: nums){
            mine = min (mine,x);
            maxe = max(maxe,x);
        }
        return gcd(mine,maxe);
    }
};