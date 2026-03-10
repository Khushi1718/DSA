// 987. Vertical Order Traversal of a Binary Tree

// Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

// For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) 
// and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

// The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column 
// index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes
//  in the same row and same column. In such a case, sort these nodes by their values.

// Return the vertical order traversal of the binary tree.
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        map<int, map<int, multiset<int>>> nodes;

        queue<pair<TreeNode*, pair<int,int>>> q;

        q.push({root,{0,0}});

        while(!q.empty()){

            auto p = q.front();
            q.pop();

            TreeNode* node = p.first;
            int row = p.second.first;
            int col = p.second.second;

            nodes[col][row].insert(node->val);

            if(node->left)
                q.push({node->left,{row+1,col-1}});

            if(node->right)
                q.push({node->right,{row+1,col+1}});
        }

        vector<vector<int>> ans;

        for(auto col : nodes){

            vector<int> temp;

            for(auto row : col.second){
                temp.insert(temp.end(), row.second.begin(), row.second.end());
            }

            ans.push_back(temp);
        }

        return ans;
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(4);

    Solution obj;

    vector<vector<int>> ans = obj.verticalTraversal(root);

    for(auto v : ans){
        for(int x : v){
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}