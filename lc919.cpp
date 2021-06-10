#include "leetcode.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
  public:
    TreeNode *_root;
    queue<TreeNode*> insertQueue;

    CBTInserter(TreeNode *root) {
        queue<TreeNode*> q;
        _root = root;
        q.push(root);
        while (!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();
            if (cur->left == nullptr || cur->right == nullptr) {
                insertQueue.push(cur);
            }
            if (cur->left) {
                q.push(cur->left);
            }
            if (cur->right) {
                q.push(cur->right);
            }
        }
    }

    int insert(int v) {
        TreeNode *cur = insertQueue.front();
        TreeNode *next = new TreeNode(v);
        insertQueue.push(next);
        if (cur->left == nullptr) {
            cur->left = next;
        } else if (cur->right == nullptr) {
            cur->right = next;
            insertQueue.pop();
        }
        return cur->val;
    }

    TreeNode *get_root() {
        return _root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */