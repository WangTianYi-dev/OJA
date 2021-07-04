#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    TreeNode *ans = nullptr;
    bool dfs(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr) {
            return false;
        }
        bool lson = dfs(root->left, p, q), rson = dfs(root->right, p, q);
        if ((lson && rson) || ((p->val == root->val || q->val == root->val) && (lson || rson))) {
            ans = root;
        }
        return lson || rson || (root->val == p->val) || (root->val == q->val);
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        dfs(root, p, q);
        return ans;
    }
};