# Day56.动规：两个字符串的删除操作、编辑距离

## 0583.两个字符串的删除操作

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







## 0072.编辑距离

链接：[0072.编辑距离](https://leetcode.cn/problems/edit-distance/)

参考：[代码随想录](https://programmercarl.com/0072.%E7%BC%96%E8%BE%91%E8%B7%9D%E7%A6%BB.html)

**dp数组**

`dp[i][j]` 表示以下标i-1为结尾的字符串word1，和以下标j-1为结尾的字符串word2，最近编辑距离为`dp[i][j]`。

**递推公式**

在确定递推公式的时候，首先要考虑清楚编辑的几种操作，整理如下：

```c++
if (word1[i - 1] == word2[j - 1])
    // 不操作
if (word1[i - 1] != word2[j - 1])
    // 增
    // 删
    // 换

```

`if (word1[i - 1] == word2[j - 1])` 那么说明不用任何编辑，`dp[i][j]` 就应该是 `dp[i - 1][j - 1]`，即`dp[i][j] = dp[i - 1][j - 1];`

`if (word1[i - 1] != word2[j - 1])`，此时就需要编辑了，如何编辑呢？

- 操作一：word1删除一个元素，那么就是以下标i - 2为结尾的word1 与 j-1为结尾的word2的最近编辑距离 再加上一个操作。

即`dp[i][j] = dp[i - 1][j] + 1;`

- 操作二：word2删除一个元素，那么就是以下标i - 1为结尾的word1 与 j-2为结尾的word2的最近编辑距离 再加上一个操作。

即`dp[i][j] = dp[i][j - 1] + 1;`

这里有同学发现了，怎么都是删除元素，添加元素去哪了。

word2添加一个元素，相当于word1删除一个元素，例如 word1 = "ad" ，word2 = "a"，word1删除元素'd' 和 word2添加一个元素'd'，变成word1="a", word2="ad"， 最终的操作数是一样！

```c++
class Solution {
public:
    int minDistance(string word1, string word2)
    {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
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
                    dp[i][j] = min({ dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] }) + 1;
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};

```





