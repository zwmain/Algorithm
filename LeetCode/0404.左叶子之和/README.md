# 0404.左叶子之和

[0404.左叶子之和](https://leetcode.cn/problems/sum-of-left-leaves/)

思路：总体递归为后序，只有在知道左右子树的左叶子和后，再相加，当前子树的目标结果。
不过遍历寻找的是左叶子节点的父节点，这样才能确定要不要返回叶子节点的值。
如果当前节点是左叶子节点的父节点，那么左子树的左叶子和就是其值，**此处不能返回**。
如果不是左叶子的父节点，那么直接递归左子树。
右子树只需直接递归。

```c++
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

```
