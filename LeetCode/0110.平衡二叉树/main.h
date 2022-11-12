#include "Utils.hpp"
#include <queue>

using namespace std;

class Solution {
public:
    bool isBalanced(TreeNode* root)
    {
        int h = getHeight(root);
        return h != -1;
    }
    int getHeight(TreeNode* node)
    {
        // 如果当前节点为空，高度为0
        if (node == nullptr) {
            return 0;
        }
        // 获取左子树高度
        int lh = getHeight(node->left);
        // 如果左子树高度返回-1，说明左子树不是平衡二叉树
        // 直接返回，没有再继续遍历的必要了
        if (lh == -1) {
            return -1;
        }
        // 右子树与左子树同理
        int rh = getHeight(node->right);
        if (rh == -1) {
            return -1;
        }
        // 子树不是平衡二叉树
        if (abs(lh - rh) > 1) {
            return -1;
        }
        // 子树是平衡二叉树，返回高度值大的+1
        return max(lh, rh) + 1;
    }
};

