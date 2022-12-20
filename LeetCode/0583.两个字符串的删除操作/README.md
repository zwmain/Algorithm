# 0583.两个字符串的删除操作

链接：[0583.两个字符串的删除操作](https://leetcode.cn/problems/distinct-subsequences/)

参考：[代码随想录](https://programmercarl.com/0583.%E4%B8%A4%E4%B8%AA%E5%AD%97%E7%AC%A6%E4%B8%B2%E7%9A%84%E5%88%A0%E9%99%A4%E6%93%8D%E4%BD%9C.html)

**dp数组含义**

`dp[i][j]`：以i-1为结尾的字符串word1，和以j-1位结尾的字符串word2，想要达到相等，所需要删除元素的最少次数。

**递推公式**

1. 当`word1[i - 1]`与`word2[j - 1]`相同的时候，`dp[i][j] = dp[i - 1][j - 1]`
2. 当`word1[i - 1]`与`word2[j - 1]`不相同的时候
   1. 删`word1[i - 1]`，最少操作次数为`dp[i - 1][j] + 1`
   2. 删`word2[j - 1]`，最少操作次数为`dp[i][j - 1] + 1`
   3. 同时删`word1[i - 1]`和`word2[j - 1]`，操作的最少次数为`dp[i - 1][j - 1] + 2`

那最后当然是取最小值，所以当`word1[i - 1]` 与 `word2[j - 1]`不相同的时候，递推公式：`dp[i][j] = min({dp[i - 1][j - 1] + 2, dp[i - 1][j] + 1, dp[i][j - 1] + 1});`

因为`dp[i - 1][j - 1] + 1`等于 `dp[i - 1][j]` 或 `dp[i][j - 1]`，所以递推公式可简化为：`dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);`

**初始化**

从递推公式中，可以看出来，`dp[i][0]` 和 `dp[0][j]`是一定要初始化的。

`dp[i][0]`：word2为空字符串，以i-1为结尾的字符串word1要删除多少个元素，才能和word2相同呢，很明显`dp[i][0] = i`。

`dp[0][j]`的话同理


```c++
class Solution {
public:
    int minDistance(string word1, string word2)
    {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1));
        for (int i = 0; i <= word1.size(); i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= word2.size(); j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};

```






