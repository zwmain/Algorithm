# 0213.打家劫舍II

链接：[0213.打家劫舍II](https://leetcode.cn/problems/house-robber-ii/)


解决环的问题：

1. 对于中间元素，和普通情况没区别
2. 只考虑首元素，不考虑尾元素
3. 只考虑尾元素，不考虑首元素

后两种包含了第一种情况

分别求后两者，然后比大小

```c++
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






