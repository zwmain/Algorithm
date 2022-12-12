# Day48.动规：打家劫舍1、2、3

## 0198.打家劫舍

链接：[0198.打家劫舍](https://leetcode.cn/problems/house-robber/)

1. 包含下标i，偷的最大值为`dp[i]`，即`[0,i]`区间
2. 递推公式：偷i，`dp[i-2]+nums[i]`，`i-1`一定不能偷了；不偷i，`dp[i-1]`；这里只是考虑到区间范围，而不是一定偷或者不偷
3. 初始化：由于`dp[i]`依赖于`i-1`和`i-2`，因此必须初始化前2个dp。`dp[0]=nums[0]`，`dp[1]=max(nums[0],nums[1])`
4. 遍历顺序：从前向后

```cpp
class Solution {
public:
    int rob(vector<int>& nums)
    {
        // 包含下标i，偷的最大值为dp[i]，即[0,i]区间
        // 递推公式：偷i，dp[i-2]+nums[i]，i-1一定不能偷了；不偷i，dp[i-1]；这里只是考虑到区间范围，而不是一定偷或者不偷
        // 初始化：由于dp[i]依赖于i-1和i-2，因此必须初始化前2个dp。dp[0]=nums[0]，dp[1]=max(nums[0],nums[1])
        // 遍历顺序：从前向后
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        // zwn::outputIntArr(dp);
        for (int i = 2; i < dp.size(); ++i) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
            // zwn::outputIntArr(dp);
        }
        return dp[nums.size() - 1];
    }
};

```





## 0213.打家劫舍II

链接：[0213.打家劫舍II](https://leetcode.cn/problems/house-robber-ii/)


解决环的问题：

1. 对于中间元素，和普通情况没区别
2. 只考虑首元素，不考虑尾元素
3. 只考虑尾元素，不考虑首元素

后两种包含了第一种情况

分别求后两者，然后比大小

```cpp
class Solution {
public:
    int rob(vector<int>& nums)
    {
        // 解决环的问题：
        // 对于中间元素，和普通情况没区别
        // 只考虑首元素，不考虑尾元素
        // 只考虑尾元素，不考虑首元素
        // 后两种包含了第一种情况
        // 分别求后两者，然后比大小

        // 包含下标i，偷的最大值为dp[i]，即[0,i]区间
        // 递推公式：偷i，dp[i-2]+nums[i]，i-1一定不能偷了；不偷i，dp[i-1]；这里只是考虑到区间范围，而不是一定偷或者不偷
        // 初始化：由于dp[i]依赖于i-1和i-2，因此必须初始化前2个dp。dp[0]=nums[0]，dp[1]=max(nums[0],nums[1])
        // 遍历顺序：从前向后
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        // zwn::outputIntArr(dp);
        for (int i = 2; i < dp.size() - 1; ++i) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
            // zwn::outputIntArr(dp);
        }
        int res1 = dp[nums.size() - 2];
        int res2 = 0;
        if (nums.size() == 2) {
            res2 = nums[1];
        } else {
            dp[1] = nums[1];
            dp[2] = max(nums[1], nums[2]);
            for (int i = 3; i < dp.size(); ++i) {
                dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
            }
            res2 = dp[nums.size() - 1];
        }
        return max(res1, res2);
    }
};

```







## 0337.打家劫舍III

链接：[0337.打家劫舍III](https://leetcode.cn/problems/house-robber-iii/)

本题一定是要后序遍历，因为通过递归函数的返回值来做下一步计算。

与198.打家劫舍，213.打家劫舍II一样，关键是要讨论当前节点抢还是不抢。

如果抢了当前节点，两个孩子就不能动，如果没抢当前节点，就可以考虑抢左右孩子（注意这里说的是“考虑”）

递归，每层都有一个dp数组，这个数组只有2个元素

`dp[0]`代表不偷，`dp[1]`代表偷

```cpp
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






