# 0098.验证二叉搜索树

链接：[0098.验证二叉搜索树](https://leetcode.cn/problems/validate-binary-search-tree/)

平衡二叉树特性：中序遍历的结果是有序的，只要确定中序结果单调，那么这个二叉树就是平衡二叉树。

判断是否单调，需要看前一个元素和后一个元素的大小，如果前一个元素大于等于当前元素，那么不单调。

初始`_pre`指针为空，当第一次走过中序时，`_pre`就是当前节点。

先看左子树，是否为平衡二叉树，再看右子树是否为平衡二叉树。

```c++
class Solution {
public:
    bool isValidBST(TreeNode* root)
    {
        if (root == nullptr) {
            return true;
        }
        bool isOk = isValidBST(root->left);
        if (!isOk) {
            return false;
        }
        if (_pre != nullptr && _pre->val > root->val) {
            return false;
        }
        _pre = root;
        isOk = isValidBST(_pre->right);
        return isOk;
    }

private:
    TreeNode* _pre = nullptr;
};

```
