// 199. Binary Tree Right Side View
// Given the root of a binary tree, imagine yourself standing on the right side of it,
//  return the values of the nodes you can see ordered from top to bottom.

#include <iostream>
#include <vector>
#include <queue>

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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};

        vector<int> v;
        queue<TreeNode*> q;

        q.push(root);
        q.push(nullptr);

        while (!q.empty()) {

            TreeNode* curr = q.front();
            q.pop();

            if (curr != nullptr && q.front() == nullptr) {
                v.push_back(curr->val);
            }

            if (curr == nullptr) {
                if (!q.empty()) {
                    q.push(nullptr);
                }
            }
            else {

                if (curr->left) {
                    q.push(curr->left);
                }

                if (curr->right) {
                    q.push(curr->right);
                }
            }
        }

        return v;
    }
};

int main() {

    /*
            1
           / \
          2   3
           \   \
            5   4
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution sol;

    vector<int> ans = sol.rightSideView(root);

    cout << "Right Side View: ";
    for (int x : ans) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
