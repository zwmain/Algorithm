#include "Utils.hpp"
#include <queue>

using namespace std;

class Solution {
public:
    int countNodes(TreeNode* root)
    {
        if (root == nullptr) {
            return 0;
        }
        int h = isFullTree(root);
        if (h > 0) {
            return pow(2, h) - 1;
        } else {
            // 如果不是满二叉树，分别求两个子树，再相加
            int lh = countNodes(root->left);
            int rh = countNodes(root->right);
            return lh + rh + 1;
        }
    }
    // 判断是否是满二叉树
    // 如果是返回深度，>=1
    // 如果不是返回0
    int isFullTree(TreeNode* node)
    {
        // 对于满二叉树来说
        // 沿着左右一路向下走，两边深度是一样的
        TreeNode* left = node->left;
        int lh = 1;
        while (left) {
            left = left->left;
            ++lh;
        }
        TreeNode* right = node->right;
        int rh = 1;
        while (right) {
            right = right->right;
            ++rh;
        }
        return lh == rh ? lh : 0;
    }
};
