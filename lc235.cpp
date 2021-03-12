#include "leetcode.h"
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int vp = p->val, vq = q->val;
        if (vp > vq) {
            swap(p, q);
            swap(vp, vq);
        }
        auto n = root;
        int vn = n->val;
        for (;;) {
            vn = n->val;
            if (vp <= vn && vn <= vq) {
                return n;
            } else if (vq < vn) {
                n = n->left;
            } else {
                n = n->right;
            }
        }
        return n;
    }
};