# 0112.路径总和

[0112.路径总和](https://leetcode.cn/problems/path-sum/)

思路；递归函数设置一个计数，计数初始值为`target`。
每次递归前计数就减去待递归节点值，如果节点为叶节点且计数为0，返回`true`，终止递归。

```c++
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum)
    {
        if (root == nullptr) {
            return false;
        }
        return recurse(root, targetSum - root->val);
    }
    bool recurse(TreeNode* node, int cnt)
    {
        if (node == nullptr) {
            return cnt == 0;
        }
        if (node->left == nullptr && node->right == nullptr) {
            return cnt == 0;
        }
        if (node->left) {
            // 显式的写出回溯过程
            cnt -= node->left->val;
            bool k = recurse(node->left, cnt);
            cnt += node->left->val;
            if (k) {
                return true;
            }
        }
        if (node->right) {
            cnt -= node->right->val;
            bool k = recurse(node->right, cnt);
            cnt += node->right->val;
            if (k) {
                return true;
            }
        }
        return false;
    }
};

```
