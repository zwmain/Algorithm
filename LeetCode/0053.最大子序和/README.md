# 0053.最大子序和

链接：[0053.最大子序和](https://leetcode.cn/problems/maximum-subarray/)

如果当前和小于0，那么只会让后面的数越来越小。在和小于0的时候，应该重置sum

动态规划：

1. `dp[i]`：包括下标i之前的最大连续子序列和为`dp[i]`。
2. `dp[i]`只有两个方向可以推出来：
   1. `dp[i - 1] + nums[i]`，即：`nums[i]`加入当前连续子序列和；
   2. `nums[i]`，即：从头开始计算当前连续子序列和；
   3. 一定是取最大的，所以`dp[i] = max(dp[i - 1] + nums[i], nums[i])`;
3. 从递推公式可以看出来`dp[i]`是依赖于`dp[i - 1]`的状态，`dp[0]`就是递推公式的基础。`dp[0] = nums[0]`
4. 递推公式中`dp[i]`依赖于`dp[i - 1]`的状态，需要从前向后遍历。


```c++
class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        if (nums.empty()) {
            return 0;
        }
        int sum = nums[0];
        int maxVal = sum;
        for (int i = 1; i < nums.size(); ++i) {
            if (sum < 0) {
                // 这里必须重置为当前值，而不是0
                sum = nums[i];
            } else {
                sum += nums[i];
            }

            // 每次sum更新后，都要更新maxVal
            if (sum > maxVal) {
                maxVal = sum;
            }
        }
        return maxVal;
    }
    int maxSubArray2(vector<int>& nums)
    {
        if (nums.empty()) {
            return 0;
        }
        // dp[i]：包括下标i之前的最大连续子序列和为dp[i]。
        // dp[i]只有两个方向可以推出来：
        // dp[i - 1] + nums[i]，即：nums[i]加入当前连续子序列和
        // nums[i]，即：从头开始计算当前连续子序列和
        // 一定是取最大的，所以dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        // 从递推公式可以看出来dp[i]是依赖于dp[i - 1]的状态，dp[0]就是递推公式的基础。dp[0] = nums[0]
        // 递推公式中dp[i]依赖于dp[i - 1]的状态，需要从前向后遍历。
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int result = dp[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            if (dp[i] > result) {
                result = dp[i];
            }
        }
        return result;
    }
};

```




