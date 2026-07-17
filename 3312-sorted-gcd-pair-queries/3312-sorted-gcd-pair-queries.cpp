// class Solution {
// public:
//     vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
//         vector<int> ans;
//         vector<int>gcdpairs;
//         //pairs 
//         for(int i = 0 ; i<nums.size();i++){
//             for(int j = i+1 ; j <nums.size();j++){
//                 gcdpairs.push_back(gcd(nums[i],nums[j]));
//             }
//         }
//         sort(gcdpairs.begin(),gcdpairs.end());
//         for(long long index: queries){
//             ans.push_back(gcdpairs[index]);
//         }
//         return ans ; 
//     }
// };
class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        // freq[i] = frequency of value i
        vector<long long> freq(mx + 1, 0);
        for (int x : nums)
            freq[x]++;

        // cnt[i] = numbers divisible by i
        vector<long long> cnt(mx + 1, 0);
        for (int i = 1; i <= mx; i++) {
            for (int j = i; j <= mx; j += i) {
                cnt[i] += freq[j];
            }
        }

        // exact[i] = number of pairs having gcd exactly i
        vector<long long> exact(mx + 1, 0);

        for (int i = mx; i >= 1; i--) {
            exact[i] = cnt[i] * (cnt[i] - 1) / 2;

            for (int j = 2 * i; j <= mx; j += i) {
                exact[i] -= exact[j];
            }
        }

        // prefix[i] = number of pairs having gcd <= i
        vector<long long> prefix(mx + 1, 0);
        for (int i = 1; i <= mx; i++) {
            prefix[i] = prefix[i - 1] + exact[i];
        }

        vector<int> ans;

        for (long long q : queries) {
            // q is 0-indexed
            int gcdValue = lower_bound(prefix.begin() + 1, prefix.end(), q + 1) - prefix.begin();
            ans.push_back(gcdValue);
        }

        return ans;
    }
};