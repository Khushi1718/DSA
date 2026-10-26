
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long need = 1LL * m * k;
        if (need > bloomDay.size())
            return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int b = 0;
            int f = 0;
            for (int day : bloomDay) {
                if (day <= mid) {
                    f++;
                    if (f == k) {
                        b++;
                        f = 0;
                    }
                } else {
                    f = 0;
                }
            }
            if (b >= m)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};
