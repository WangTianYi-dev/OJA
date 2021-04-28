
// Definition for a binary tree node.
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

#include "leetcode.h"
struct TreeNode;
class BSTIterator {
public:
    deque<int> dq;

    void traverseIn(deque<int>& dq, TreeNode* root)
    {
        stack<TreeNode*> s;
        auto t = root ? root : nullptr;
        for (;;) {
            while (t) {
                s.push(t);
                t = t->left;
            }
            if (s.empty())
                break;
            t = s.top();
            s.pop();
            dq.emplace_back(t->val);
            t = t->right;
        }
    }

    BSTIterator(TreeNode* root)
    {
        traverseIn(dq, root);
    }

    int next()
    {
        int t = dq.front();
        dq.pop_front();
        return t;
    }

    bool hasNext()
    {
        return dq.size() > 0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */