#include "Utils.hpp"
#include <string>
#include <vector>

using namespace std;

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
