#include "leetcode.h"

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        q.emplace(root);
        while (!q.empty()) {
            int curSize = q.size();
            vector<int> v;
            for (int i = 0; i < curSize; i++) {
                auto t = q.front();
                q.pop();
                v.emplace_back(t->val);
                if (t->left) {
                    q.emplace(t->left);
                }
                if (t->right) {
                    q.emplace(t->right);
                }
            }
            res.emplace_back(v);
        }
        return res;
    }
};