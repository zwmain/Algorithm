# Day46.动规：单词拆分

链接：[0139.单词拆分](https://leetcode.cn/problems/word-break/)

字符串理解为容器，背包

子串理解为物品，物品可以使用多次

1. 字符串长度为i，如果长度为i的字符串可以由列表组成，那么`dp[i]`为true，注意这里i是长度，不是下标
2. 递推公式：如果`[j,i]`区间在列表里且`dp[j]`为true，那么`dp[i]`就为true
3. 初始化：`dp[0]=true`，为了保证递推公式能正常进行，其它下标都为false
4. 遍历顺序：先遍历背包，再遍历物品，排列数

```c++
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        // 字符串理解为容器，背包
        // 子串理解为物品，物品可以使用多次
        // 字符串长度为i，如果长度为i的字符串可以由列表组成，那么dp[i]为true，注意这里i是长度，不是下标
        // 递推公式：如果[j,i]区间在列表里且dp[j]为true，那么dp[i]就为true
        // 初始化：dp[0]=true，为了保证递推公式能正常进行，其它下标都为false
        // 遍历顺序：先遍历背包，再遍历物品，排列数
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                // 截取[j,i]字符串
                string w = s.substr(j, i - j);
                bool isFind = false;
                for (auto& t : wordDict) {
                    if (t == w) {
                        isFind = true;
                        break;
                    }
                }
                if (isFind && dp[j]) {
                    dp[i] = true;
                }
            }
        }
        return dp[s.size()];
    }
};

```




