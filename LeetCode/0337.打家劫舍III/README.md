# 0337.打家劫舍III

链接：[0337.打家劫舍III](https://leetcode.cn/problems/house-robber-iii/)

本题一定是要后序遍历，因为通过递归函数的返回值来做下一步计算。

与198.打家劫舍，213.打家劫舍II一样，关键是要讨论当前节点抢还是不抢。

如果抢了当前节点，两个孩子就不能动，如果没抢当前节点，就可以考虑抢左右孩子（注意这里说的是“考虑”）

递归，每层都有一个dp数组，这个数组只有2个元素

`dp[0]`代表不偷，`dp[1]`代表偷

```c++
class Solution {
public:
    int rob(TreeNode* root)
    {
        // 递归，每层都有一个dp数组，这个数组只有2个元素
        // dp[0]代表不偷，dp[1]代表偷
        auto dp = recurse(root);
        return max(dp[0], dp[1]);
    }

    vector<int> recurse(TreeNode* node)
    {
        if (node == nullptr) {
            return { 0, 0 };
        }
        // 获取子节点偷与不偷的情况
        auto left = recurse(node->left);
        auto right = recurse(node->right);
        // 偷当前节点
        // 左右孩子都不能偷
        int res1 = node->val + left[0] + right[0];
        // 不偷当前节点
        // 左右孩子可以偷也可以不偷，看哪种情况最大
        int res2 = max(left[0], left[1]) + max(right[0], right[1]);
        return { res2, res1 };
    }
};

```






