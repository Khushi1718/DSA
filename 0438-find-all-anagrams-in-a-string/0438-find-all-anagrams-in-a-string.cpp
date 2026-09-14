class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int left = 0;
        int m = p.length();
        unordered_map<char, int> mp;
        for (char ch : p) {
            mp[ch]++;
        }
        unordered_map<char, int> ms;
        for (int i = 0; i < s.length(); i++) {
            ms[s[i]]++;
            if (i - left + 1 == m) {
                if (ms == mp) {
                    ans.push_back(left);
                }
                ms[s[left]]--;
                if (ms[s[left]] == 0) {
                    ms.erase(s[left]);
                }
                left++;
            }
        }
        return ans;
    }
};