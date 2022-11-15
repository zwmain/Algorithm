# 0530.二叉搜索树的最小绝对差

链接：[0530.二叉搜索树的最小绝对差](https://leetcode.cn/problems/minimum-absolute-difference-in-bst/)

二叉搜索树，在中序遍历下是一个有序数组。那么最小绝对差一定从相邻两个数的绝对差中产生。

中序遍历二叉树，维护一个`pre`指针，指向前一个元素，每次更新绝对差。

```c++
class Solution {
public:
    int getMinimumDifference(TreeNode* root)
    {
        midRecurse(root);
        return _minVal;
    }

private:
    void midRecurse(TreeNode* node)
    {
        if (node == nullptr) {
            return;
        }
        midRecurse(node->left);
        if (_pre != nullptr) {
            int n = abs(node->val - _pre->val);
            if (n < _minVal) {
                _minVal = n;
            }
        }
        _pre = node;
        midRecurse(node->right);
    }

    TreeNode* _pre = nullptr;
    int _minVal = INT_MAX;
};

```
