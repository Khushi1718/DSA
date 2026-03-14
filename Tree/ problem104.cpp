// 104. Maximum Depth of Binary Tree

// Given the root of a binary tree, return its maximum depth.

// A binary tree's maximum depth is the number of 
// nodes along the longest path from the root node down to the farthest leaf node.

#include <iostream>
#include <queue>
using namespace std;

// Definition for a binary tree node.
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
    int maxDepth(TreeNode* root){
        if(root==nullptr) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int depth=0;

        while(!q.empty()){
            int n = q.size();
            depth++;

            for(int i=0;i<n;i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
        }
        return depth;
    }
};

int main(){

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution obj;
    cout << "Max Depth: " << obj.maxDepth(root);

    return 0;
}