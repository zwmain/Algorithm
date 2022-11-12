#include "Utils.hpp"

using namespace std;

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root)
    {
        return getLeftSum(root);
    }
    int getLeftSum(TreeNode* node)
    {
        // 空节点，左叶子节点的和为0
        if (node == nullptr) {
            return 0;
        }
        if (node->left == nullptr && node->right == nullptr) {
            // 如果当前节点是叶子节点，但并不能确定是不是左叶子节点
            // 返回0
            return 0;
        }
        TreeNode* lc = node->left;
        int sumLeft = 0;
        if (lc != nullptr && lc->left == nullptr && lc->right == nullptr) {
            // 如果当前节点是左叶子节点的父节点
            // 那么左叶子节点的和就是左节点的值
            sumLeft = lc->val;
        } else {
            sumLeft = getLeftSum(node->left);
        }

        int sumRight = getLeftSum(node->right);

        return sumLeft + sumRight;
    }
};
