# 1143.最长公共子序列

链接：[1143.最长公共子序列](https://leetcode.cn/problems/longest-common-subsequence/)


1. `dp[i][j]`，`text1[0,i]`与`text2[0,j]`，的最长公共子序列为`dp[i][j]`
2. 递推公式：两种情况，`text1[i]`与`text2[j]`相同或者不相同
3. 如果两个子串的末尾相同，那么`dp[i][j]=dp[i-1][j-1]+1`。如果两个子串的末尾不同，那么就观察`text1[0,i-1]`与`text2[0,j]`，`text1[0,i]`与`text2[0,j-1]`，它们公共子串的长度。取最大值，`max(dp[i][j-1],dp[j][i-1])`
4. 初始化：i，j都会依赖`i-1`，`j-1`。因此，`dp[0][j]`和`dp[i][0]`需要初始化。如果`text1[0]`与`text2[j]`不同，那么`dp[0][j]`为0，从第一个相同的时候开始，后面全为1
5. 遍历顺序：`dp[i][j]`都依赖`i-1`，`j-1`，所以从小到大遍历

```c++
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






