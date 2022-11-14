#include "Utils.hpp"

using namespace std;

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val)
    {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->val == val) {
            return root;
        } else if (root->val < val) {
            return searchBST(root->right, val);
        } else {
            return searchBST(root->left, val);
        }
    }
    TreeNode* searchBST2(TreeNode* root, int val)
    {
        while (root) {
            if (root->val == val) {
                return root;
            } else if (root->val < val) {
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return root;
    }
};
