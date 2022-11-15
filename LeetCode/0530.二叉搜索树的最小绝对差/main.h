#include "Utils.hpp"

using namespace std;

class Solution {
public:
    int getMinimumDifference(TreeNode* root)
    {
        midRecurse(root);
        return _minVal;
    }

private:
    void midRecurse(TreeNode* node)
    {
        if (node == nullptr) {
            return;
        }
        midRecurse(node->left);
        if (_pre != nullptr) {
            int n = abs(node->val - _pre->val);
            if (n < _minVal) {
                _minVal = n;
            }
        }
        _pre = node;
        midRecurse(node->right);
    }

    TreeNode* _pre = nullptr;
    int _minVal = INT_MAX;
};
