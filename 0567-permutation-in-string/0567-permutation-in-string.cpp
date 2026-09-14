class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> mp, ms;
        int m = s1.length();
        for(char ch : s1) mp[ch]++;
        int left = 0;
        for(int right = 0; right < s2.length(); right++){
            ms[s2[right]]++;
            if(right - left + 1 == m){
                if(ms == mp) return true;
                ms[s2[left]]--;
                if(ms[s2[left]] == 0) ms.erase(s2[left]);
                left++;
            }
        }
        return false;
    }
};