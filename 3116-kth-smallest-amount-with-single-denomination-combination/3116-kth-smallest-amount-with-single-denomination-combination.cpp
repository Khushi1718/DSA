// // class Solution {
// // public:
// //     long long findKthSmallest(vector<int>& coins, int k) {
// //         int n = coins.size();
// //         vector<int>index(n,1);
// //         sort(coins.begin(), coins.end());
// //         long long ans = coins[0];
// //         index[0]++;
// //         k--;
// //         while(k>0){
// //             map<int, vector<int>> mp;
// //             int smallest = INT_MAX;
// //             for(int i = 0 ; i <n;i++){
// //                 int val = coins[i]*index[i];
// //                 mp[val].push_back(i);
// //                 smallest = min(smallest,val);
// //             }
            
// //             for(int x : mp[smallest]){
// //                 index[x]++;
// //             }
// //             ans = smallest;
// //             k--;
// //         }
// //         return ans;
// //     }
// // };
// class Solution {
// public:
//     long long findKthSmallest(vector<int>& coins, int k) {

//         int n = coins.size();
//         priority_queue<
//             pair<long long, int>,
//             vector<pair<long long, int>>,
//             greater<pair<long long, int>>
//         > pq;

//         vector<long long> index(n, 1);
//         for (int i = 0; i < n; i++) {
//             pq.push({coins[i], i});
//         }
//         long long ans = 0;
//         while (k > 0) {
//             long long smallest = pq.top().first;
//             ans = smallest;
//             while (!pq.empty() && pq.top().first == smallest) {
//                 int i = pq.top().second;
//                 pq.pop();
//                 index[i]++;
//                 long long next = 1LL * coins[i] * index[i];
//                 pq.push({next, i});
//             }
//             k--;
//         }

//         return ans;
//     }
// };

class Solution {
public:

    long long gcd(long long a, long long b) {
        while (b) {
            long long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    // X tak kitne DISTINCT amounts ban sakte hain
    long long count(long long X, vector<int>& coins) {

        int n = coins.size();
        long long ans = 0;

        // All subsets of coins
        for (int mask = 1; mask < (1 << n); mask++) {

            long long L = 1;
            int bits = 0;
            bool valid = true;

            for (int i = 0; i < n; i++) {

                if (mask & (1 << i)) {
                    bits++;

                    L = lcm(L, coins[i]);

                    // L > X means no multiple <= X
                    if (L > X) {
                        valid = false;
                        break;
                    }
                }
            }

            if (!valid)
                continue;

            long long ways = X / L;

            // Odd number of coins -> add
            // Even number -> subtract
            if (bits % 2 == 1)
                ans += ways;
            else
                ans -= ways;
        }

        return ans;
    }

    long long findKthSmallest(vector<int>& coins, int k) {

        long long lo = *min_element(coins.begin(), coins.end());
        long long hi = lo * 1LL * k;

        while (lo < hi) {

            long long mid = lo + (hi - lo) / 2;

            if (count(mid, coins) >= k) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return lo;
    }
};