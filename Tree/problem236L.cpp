// 236. Lowest Common Ancestor of a Binary Tree

// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest
//  node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

#include <iostream>
#include <queue>
#include <map>
#include <set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    // BRUTE FORCE APPROACH
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        map<TreeNode*, TreeNode*> parent;   // stores parent of every node
        queue<TreeNode*> qu;

        parent[root] = NULL; // root has no parent
        qu.push(root);

        // BFS traversal to build parent map
        while (!qu.empty() && (parent.find(p) == parent.end() || parent.find(q) == parent.end())) {

            TreeNode* curr = qu.front();
            qu.pop();

            if (curr->left) {
                parent[curr->left] = curr;
                qu.push(curr->left);
            }

            if (curr->right) {
                parent[curr->right] = curr;
                qu.push(curr->right);
            }
        }

        // Store all ancestors of p
        set<TreeNode*> ancestors;

        while (p != NULL) {
            ancestors.insert(p);
            p = parent[p];
        }

        // Move upward from q until we find common ancestor
        while (ancestors.find(q) == ancestors.end()) {
            q = parent[q];
        }

        return q;
    }
};
class Solution {
public:
    // OPTIMAL APPROACH (DFS RECURSION)

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)
            return NULL;
        if (root == p || root == q)
            return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left != NULL && right != NULL)
            return root;

        if (left != NULL)
            return left;

        return right;
    }
};