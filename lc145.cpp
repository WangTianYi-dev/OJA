#include "leetcode.h"

// void postOrderTraversalIterative(BinaryTree* root)
// {
//     if (!root)
//         return;
//     stack<BinaryTree*> s;
//     s.push(root);
//     BinaryTree* prev = NULL;
//     while (!s.empty()) {
//         BinaryTree* curr = s.top();
//         if (!prev || prev->left == curr || prev->right == curr) {
//             if (curr->left)
//                 s.push(curr->left);
//             else if (curr->right)
//                 s.push(curr->right);
//         } else if (curr->left == prev) {
//             if (curr->right)
//                 s.push(curr->right);
//         } else {
//             cout << curr->data << " ";
//             s.pop();
//         }
//         prev = curr;
//     }
// }

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

class Solution {
public:
public:
    
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        TreeNode* prev = nullptr;
        stack<TreeNode*> s;
        while (!s.empty() || root != nullptr) {
            while (root != nullptr) {
                if (root->left) {
                    s.emplace(root->left);
                }
            }
            root = s.top();
            s.pop();
            if (!root->right || prev == root->right) {
                res.emplace_back(root->val);
                prev = root;
                root = nullptr;
            } else {
                s.emplace(root);
                root = root->right;
            }
        }
        return res;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/binary-tree-postorder-traversal/solution/er-cha-shu-de-hou-xu-bian-li-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。