# 0222.完全二叉树的节点个数

链接：[0222.完全二叉树的节点个数](https://leetcode.cn/problems/count-complete-tree-nodes/)

因为是完全二叉树，如果整棵树不是满二叉树，那么局部子树也一定存在满二叉树，只要判断处满二叉树就可以利用公式，直接求出数量。

对于满二叉树来说，分别沿着左右两边一直走下去，深度是一致的。

如果以当前节点为根节点的子树不是满二叉树，那么就向普通树那样，分别求两颗子树，再相加。

```c++
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

```
