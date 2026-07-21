class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int ones = 0;
        int bestGain = 0;
        int prevZeroBlock = INT_MIN;
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;

            int len = j - i;

            if (s[i] == '1') {
                ones += len;
            } else {
                bestGain = max(bestGain, prevZeroBlock + len);
                prevZeroBlock = len;
            }

            i = j;
        }
        return ones + bestGain;
    }
};