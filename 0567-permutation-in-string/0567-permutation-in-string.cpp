class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;
        vector<int> a(26, 0), b(26, 0);
        int m = s1.length();
        for(char ch : s1) a[ch - 'a']++;
        for(int i = 0; i < m; i++) b[s2[i] - 'a']++;
        if(a == b) return true;
        for(int right = m; right < s2.length(); right++){
            b[s2[right] - 'a']++;
            b[s2[right - m] - 'a']--;
            if(a == b) return true;
        }
        return false;
    }
};