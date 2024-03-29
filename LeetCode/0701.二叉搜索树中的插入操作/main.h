#include "Utils.hpp"

using namespace std;

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val)
    {
        if (root == nullptr) {
            TreeNode* node = new TreeNode(val);
            return node;
        }

        if (root->val > val) {
            root->left = insertIntoBST(root->left, val);
        } else if (root->val < val) {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};
