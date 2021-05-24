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
#include "leetcode.h"

class Solution {
  public:
    bool isCousins(TreeNode *root, int x, int y) {
        struct node {
            TreeNode *parent;
            TreeNode *self;
            int depth;
        };
        vector<node> res;
        queue<node> q;
        q.push({.parent = nullptr, .self = root, .depth = 0});
        while (!q.empty()) {
            node cur = q.front();
            q.pop();
            TreeNode *self = cur.self;
            TreeNode *parent = cur.parent;
            int curDep = cur.depth;
            if (self->val == x || self->val == y) {
                res.push_back(cur);
            }
            if (self->right) {
                q.push({.parent = self, .self = self->right, .depth = curDep + 1});
            }
            if (self->left) {
                q.push({.parent = self, .self = self->left, .depth = curDep + 1});
            }
        }
        if (res.size() == 2 && res[0].depth == res[1].depth && res[0].parent != res[1].parent) {
            return true;
        }
        return false;
    }
};
