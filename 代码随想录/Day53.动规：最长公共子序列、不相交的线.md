# Day53.动规：最长公共子序列、不相交的线


## 1143.最长公共子序列

链接：[1143.最长公共子序列](https://leetcode.cn/problems/longest-common-subsequence/)


1. `dp[i][j]`，`text1[0,i]`与`text2[0,j]`，的最长公共子序列为`dp[i][j]`
2. 递推公式：两种情况，`text1[i]`与`text2[j]`相同或者不相同
3. 如果两个子串的末尾相同，那么`dp[i][j]=dp[i-1][j-1]+1`。如果两个子串的末尾不同，那么就观察`text1[0,i-1]`与`text2[0,j]`，`text1[0,i]`与`text2[0,j-1]`，它们公共子串的长度。取最大值，`max(dp[i][j-1],dp[j][i-1])`
4. 初始化：i，j都会依赖`i-1`，`j-1`。因此，`dp[0][j]`和`dp[i][0]`需要初始化。如果`text1[0]`与`text2[j]`不同，那么`dp[0][j]`为0，从第一个相同的时候开始，后面全为1
5. 遍历顺序：`dp[i][j]`都依赖`i-1`，`j-1`，所以从小到大遍历

```cpp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        // dp[i][j]，text1[0,i]与text2[0,j]，的最长公共子序列为dp[i][j]
        // 递推公式：两种情况，text1[i]与text2[j]相同或者不相同
        // 如果两个子串的末尾相同，那么dp[i][j]=dp[i-1][j-1]+1
        // 如果两个子串的末尾不同，那么就观察text1[0,i-1]与text2[0,j]，text1[0,i]与text2[0,j-1]，它们公共子串的长度
        // 取最大值，max(dp[i][j-1],dp[j][i-1])
        // 初始化：i，j都会依赖i-1，j-1。因此，dp[0][j]和dp[i][0]需要初始化。如果text1[0]与text2[j]不同，那么dp[0][j]为0，从第一个相同的时候开始，后面全为1
        // 遍历顺序：dp[i][j]都依赖i-1,j-1，所以从小到大遍历
        if (text1.empty() || text2.empty()) {
            return 0;
        }
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), 0));
        int val = 0;
        for (size_t i = 0; i < text1.size(); ++i) {
            if (text1[i] == text2[0]) {
                val = 1;
            }
            dp[i][0] = val;
        }
        val = 0;
        for (size_t j = 0; j < text2.size(); ++j) {
            if (text1[0] == text2[j]) {
                val = 1;
            }
            dp[0][j] = val;
        }
        for (size_t i = 1; i < text1.size(); ++i) {
            for (size_t j = 1; j < text2.size(); ++j) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp.back().back();
    }
};

```







## 1035.不相交的线

链接：[1035.不相交的线](https://leetcode.cn/problems/uncrossed-lines/)

本题与[1143.最长公共子序列](https://leetcode.cn/problems/longest-common-subsequence/)一致


```cpp
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2)
    {
        // 本题与最长公共子序列一致
        if(nums1.empty()||nums2.empty()){
            return 0;
        }
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), 0));
        int val = 0;
        for (size_t i = 0; i < nums1.size(); ++i) {
            if (nums1[i] == nums2[0]) {
                val = 1;
            }
            dp[i][0] = val;
        }
        val = 0;
        for (size_t j = 0; j < nums2.size(); ++j) {
            if (nums1[0] == nums2[j]) {
                val = 1;
            }
            dp[0][j] = val;
        }
        for (size_t i = 1; i < nums1.size(); ++i) {
            for (size_t j = 1; j < nums2.size(); ++j) {
                if (nums1[i] == nums2[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp.back().back();
    }
};

```








## 0053.最大子序和

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


```cpp
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




