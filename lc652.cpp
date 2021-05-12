#include "leetcode.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
  public:
    unordered_map<int, int> m;
    int sumId = 0;
    vector<TreeNode *> res;
    unordered_map<tuple<int, int, int>, int> tree;
    int countId(TreeNode *n) {
        tuple<int, int, int> reg = make_tuple(n->val, countId(n->left), countId(n->right));
        int curId;
        if (tree.find(reg) == tree.end()) {
            curId = sumId;
            tree[reg] = sumId;
            m[sumId]++;
            sumId++;
        } else {
            curId = tree[reg];
            m[curId]++;
            if (m[curId] == 2) {
                res.push_back(n);
            }
        }
        return sumId;
    }

    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
        countId(root);
        return res;
    }
};