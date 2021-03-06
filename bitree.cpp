#include "leetcode.h"
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
        : val(0)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x)
        , left(left)
        , right(right)
    {
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> v;
        stack<TreeNode*> s;
        if (root) {
            s.push(root);
        }
        auto p = root ? root->left : nullptr;
        for (;;) {
            while (p) {
                s.push(p);
                p = p->left;
            }
            if (s.empty()) {
                break;
            }
            p = s.top();
            s.pop();
            v.push_back(p->val);
            p = p->right;
        }
        return v;
    }
};