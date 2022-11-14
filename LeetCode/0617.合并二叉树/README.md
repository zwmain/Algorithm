# 0617.合并二叉树

链接：[0617.合并二叉树](https://leetcode.cn/problems/merge-two-binary-trees/)

思路：同时递归两个树，保证二者同步，都递归左子树或都递归右子树，这里在root1的基础上改造，而不是新建一棵树。

```c++
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2)
    {
        // 如果root1为空，直接返回root2
        // 这里已经包含了二者都为空的情况
        if (root1 == nullptr) {
            return root2;
        }
        if (root2 == nullptr) {
            return root1;
        }
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};

```
