#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

// solution 1 (NULL marker method)

vector<vector<int>> levelOrder1(TreeNode* root) {
    if(root == nullptr) return {};

    vector<vector<int>> ans;
    vector<int> temp;
    queue<TreeNode*> q;

    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();

        if(curr == nullptr){
            ans.push_back(temp);
            temp.clear();

            if(!q.empty()){
                q.push(nullptr);
            }
        }
        else{
            temp.push_back(curr->val);

            if(curr->left){
                q.push(curr->left);
            }

            if(curr->right){
                q.push(curr->right);
            }
        }
    }

    return ans;
}


// solution 2 (queue size method - better)

vector<vector<int>> levelOrder2(TreeNode* root) {
    if(!root) return {};

    vector<vector<int>> ans;
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        int n = q.size();
        vector<int> temp;

        for(int i=0;i<n;i++){
            TreeNode* curr = q.front();
            q.pop();

            temp.push_back(curr->val);

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }

        ans.push_back(temp);
    }

    return ans;
}


int main(){

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<vector<int>> ans = levelOrder2(root);

    for(auto level : ans){
        for(auto x : level){
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}