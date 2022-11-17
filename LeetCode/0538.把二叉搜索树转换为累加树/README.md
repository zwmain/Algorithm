# 0538.把二叉搜索树转换为累加树

链接：[0538.把二叉搜索树转换为累加树](https://leetcode.cn/problems/convert-bst-to-greater-tree/)

二叉搜索树的中序遍历为一个递增有序数组，如果依然保持中序，但是调换左右子树位置，那么结果就是递减的有序数组。

由于目标值需要累加，所以记录一个`pre`节点，以便累加。

```c++
class Solution {
public:
    TreeNode* convertBST(TreeNode* root)
    {
        if (root == nullptr) {
            return nullptr;
        }
        root->right = convertBST(root->right);
        if (_pre != nullptr) {
            root->val += _pre->val;
        }
        _pre = root;
        root->left = convertBST(root->left);
        return root;
    }

private:
    TreeNode* _pre = nullptr;
};

```

