// 103. Binary Tree Zigzag Level Order Traversal
// Given the root of a binary tree, return the zigzag level order traversal of its nodes 
//  values. (i.e., from left to right, then right to left for the next level and alternate between).
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};

        vector<vector<int>> result;
        vector<int> v;

        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);

        int level = 1;

        while (!q.empty()) {

            TreeNode* curr = q.front();
            q.pop();

            if (curr == nullptr) {

                if (level % 2 == 0) {
                    reverse(v.begin(), v.end());
                }

                result.push_back(v);
                v.clear();
                level++;

                if (!q.empty()) {
                    q.push(nullptr);
                }
            }
            else {

                v.push_back(curr->val);

                if (curr->left) {
                    q.push(curr->left);
                }

                if (curr->right) {
                    q.push(curr->right);
                }
            }
        }

        return result;
    }
};

int main() {

    /*
            1
           / \
          2   3
         / \ / \
        4  5 6  7
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution sol;

    vector<vector<int>> ans = sol.zigzagLevelOrder(root);

    cout << "Zigzag Level Order Traversal:\n";

    for (auto level : ans) {
        for (int x : level) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
