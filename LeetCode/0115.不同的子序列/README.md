# 0115.不同的子序列

链接：[0115.不同的子序列](https://leetcode.cn/problems/distinct-subsequences/)

参考：[代码随想录](https://programmercarl.com/0115.%E4%B8%8D%E5%90%8C%E7%9A%84%E5%AD%90%E5%BA%8F%E5%88%97.html)

这题中间计算会溢出。。。

**dp数组含义**

`dp[i][j]`：以i-1为结尾的s子序列中出现以j-1为结尾的t的个数为`dp[i][j]`。

**递推公式**

这一类问题，基本是要分析两种情况

- `s[i - 1]` 与 `t[j - 1]`相等
- `s[i - 1]` 与 `t[j - 1]`不相等

当`s[i - 1]` 与 `t[j - 1]`相等时，`dp[i][j]`可以有两部分组成。

一部分是用`s[i - 1]`来匹配，那么个数为`dp[i - 1][j - 1]`。

一部分是不用`s[i - 1]`来匹配，个数为`dp[i - 1][j]`。

为什么还要考虑 不用`s[i - 1]`来匹配，都相同了指定要匹配啊。

例如： s：bagg 和 t：bag ，`s[3]` 和 `t[2]`是相同的，但是字符串s也可以不用`s[3]`来匹配，即用`s[0]s[1]s[2]`组成的bag。

当然也可以用`s[3]`来匹配，即：`s[0]s[1]s[3]`组成的bag。

所以当`s[i - 1]` 与 `t[j - 1]`相等时，`dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]`

当`s[i - 1]` 与 `t[j - 1]`不相等时，`dp[i][j]`只有一部分组成，不用`s[i - 1]`来匹配，即：`dp[i - 1][j]`。所以递推公式为：`dp[i][j] = dp[i - 1][j]`

**初始化**

从递推公式`dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];` 和 `dp[i][j] = dp[i - 1][j];` 中可以看出`dp[i][0]` 和`dp[0][j]`是一定要初始化的。

每次当初始化的时候，都要回顾一下`dp[i][j]`的定义，不要凭感觉初始化。

`dp[i][0]`表示什么呢？

`dp[i][0]` 表示：以i-1为结尾的s可以随便删除元素，出现空字符串的个数。

那么`dp[i][0]`一定都是1，因为也就是把以i-1为结尾的s，删除所有元素，出现空字符串的个数就是1。

再来看`dp[0][j]`，`dp[0][j]`：空字符串s可以随便删除元素，出现以j-1为结尾的字符串t的个数。

那么`dp[0][j]`一定都是0，s如论如何也变成不了t。

最后就要看一个特殊位置了，即：`dp[0][0]` 应该是多少。

`dp[0][0]`应该是1，空字符串s，可以删除0个元素，变成空字符串t。


```c++
class Solution {
public:
    int numDistinct(string s, string t)
    {
        if (s.size() < t.size()) {
            return 0;
        }
        if (t.empty()) {
            return 1;
        }
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for (int i = 0; i < dp.size(); ++i) {
            dp[i][0] = 1;
        }
        for (int j = 1; j < dp[0].size(); ++j) {
            dp[0][j] = 0;
        }
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 1; j <= t.size(); ++j) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        zwn::outputIntArrArr(dp);
        return dp.back().back();
    }
};

```




