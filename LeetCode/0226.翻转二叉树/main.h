#include "Utils.hpp"
#include <stack>

using namespace std;

class Solution {
public:
    TreeNode* invertTree(TreeNode* root)
    {
        if (root == nullptr) {
            return nullptr;
        }
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
    TreeNode* invertTree2(TreeNode* root)
    {
        if (root == nullptr) {
            return nullptr;
        }
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* cur = stk.top();
            stk.pop();
            swap(cur->left, cur->right);
            if (cur->left) {
                stk.push(cur->left);
            }
            if (cur->right) {
                stk.push(cur->right);
            }
        }
        return root;
    }
};
