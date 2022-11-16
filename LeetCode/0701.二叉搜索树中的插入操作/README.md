# 0701.二叉搜索树中的插入操作

链接：[0701.二叉搜索树中的插入操作](https://leetcode.cn/problems/insert-into-a-binary-search-tree/)

这题不要想复杂了，就是普通插入，比当前值大，就去右子树；比当前值小就去左子树；等于当前值，就直接返回。

当找到空节点的时候，就是目标位置，返回新创建的节点。然后在递归进来的位置接收。

```c++
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val)
    {
        if (root == nullptr) {
            TreeNode* node = new TreeNode(val);
            return node;
        }

        if (root->val > val) {
            root->left = insertIntoBST(root->left, val);
        } else if (root->val < val) {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};

```
