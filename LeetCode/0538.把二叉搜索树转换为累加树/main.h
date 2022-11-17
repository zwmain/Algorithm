#include "Utils.hpp"

using namespace std;

class Solution {
public:
    TreeNode* convertBST(TreeNode* root)
    {
        if (root == nullptr) {
            return nullptr;
        }
        root->right = convertBST(root->right);
        if (_pre != nullptr) {
            root->val += _pre->val;
        }
        _pre = root;
        root->left = convertBST(root->left);
        return root;
    }

private:
    TreeNode* _pre = nullptr;
};
