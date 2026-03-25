#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solve(int index, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans) {
        ans.push_back(temp); 

        for (int i = index; i < nums.size(); i++) {
            temp.push_back(nums[i]);  
            solve(i + 1, nums, temp, ans);
            temp.pop_back();            
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(0, nums, temp, ans);
        return ans;
    }
};

int main() {
    Solution obj;
    
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = obj.subsets(nums);

    for (auto &vec : result) {
        cout << "[ ";
        for (int x : vec) cout << x << " ";
        cout << "]\n";
    }

    return 0;
}