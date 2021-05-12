

#include "leetcode.h"
class Solution {
  public:
    vector<int> v1, v2;
    void getThrough(TreeNode *root, vector<int> &v) {
        if (root->left) {
            getThrough(root->left, v);
        }
        if (!root->left && !root->right) {
            v.push_back(root->val);
        }
        if (root->right) {
            getThrough(root->right, v);
        }
    }

    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        getThrough(root1, v1);
        getThrough(root2, v2);
        if (v1.size() != v2.size()) {
            return false;
        }
        for (int i = 0; i < v1.size(); i++) {
            if (v1[i] != v2[i])
                return false;
        }
        return true;
    }
};