#include <iostream>
#include <vector>
using namespace std;

void solve(int start, int n, int k, vector<int>& temp, vector<vector<int>>& ans) {
    // base case
    if (temp.size() == k) {
        ans.push_back(temp);
        return;
    }

    for (int i = start; i <= n; i++) {
        temp.push_back(i);           
        solve(i + 1, n, k, temp, ans);
        temp.pop_back();            
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> temp;

    solve(1, n, k, temp, ans);
    return ans;
}

int main() {
    int n = 4, k = 2;
    vector<vector<int>> result = combine(n, k);

    for (auto &vec : result) {
        for (int x : vec) cout << x << " ";
        cout << endl;
    }

    return 0;
}