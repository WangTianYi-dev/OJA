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
    unordered_map<int, TreeNode *> father;
    unordered_set<int> vised;
    void traverse(TreeNode *n) {
        if (n->left != nullptr) {
            father[n->left->val] = n;
            traverse(n->left);
        }
        if (n->right != nullptr) {
            father[n->right->val] = n;
            traverse(n->right);
        }
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        father[root->val] = nullptr;
        traverse(root);
        TreeNode *tn = p;
        while (tn != nullptr) {
            vised.insert(tn->val);
            tn = father[tn->val];
        }
        tn = q;
        while (tn != nullptr) {
            if (vised.count(tn->val)) {
                return tn;
            }
            tn = father[tn->val];
        }
        return tn;
    }
};