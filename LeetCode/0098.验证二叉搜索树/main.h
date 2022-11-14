#include "Utils.hpp"

using namespace std;

class Solution {
public:
    bool isValidBST(TreeNode* root)
    {
        if (root == nullptr) {
            return true;
        }
        bool isOk = isValidBST(root->left);
        if (!isOk) {
            return false;
        }
        if (_pre != nullptr && _pre->val > root->val) {
            return false;
        }
        _pre = root;
        isOk = isValidBST(_pre->right);
        return isOk;
    }

private:
    TreeNode* _pre = nullptr;
};
