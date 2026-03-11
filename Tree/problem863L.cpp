#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

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
    unordered_map<TreeNode*, TreeNode*> parent;

    void markParents(TreeNode* root, TreeNode* par) {
        if (!root) return;

        parent[root] = par;

        markParents(root->left, root);
        markParents(root->right, root);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        markParents(root, nullptr);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        q.push(target);
        visited.insert(target);

        int dist = 0;

        while (!q.empty()) {

            int size = q.size();

            if (dist == k) break;

            for (int i = 0; i < size; i++) {

                TreeNode* curr = q.front();
                q.pop();

                if (curr->left && !visited.count(curr->left)) {
                    q.push(curr->left);
                    visited.insert(curr->left);
                }

                if (curr->right && !visited.count(curr->right)) {
                    q.push(curr->right);
                    visited.insert(curr->right);
                }

                if (parent[curr] && !visited.count(parent[curr])) {
                    q.push(parent[curr]);
                    visited.insert(parent[curr]);
                }
            }

            dist++;
        }

        vector<int> ans;

        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution sol;

    TreeNode* target = root->left; // node 5
    int k = 2;

    vector<int> result = sol.distanceK(root, target, k);

    cout << "Nodes at distance " << k << " from target: ";
    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}