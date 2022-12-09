# 0322.零钱兑换

链接：[0322.零钱兑换](https://leetcode.cn/problems/coin-change/)

1. `dp[j]`，装满容量为j的背包，最少钱币
2. 递推公式：`dp[j]=min(dp[j-coins[i]]+1,dp[j])`
3. 初始化：`dp[0]=0`，非零下标初始为INT_MAX
4. 遍历顺序：先遍历物品，再遍历背包，组合数；先遍历背包，后遍历物品，排列数；本题无所谓

```c++
class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        // dp[j]，装满容量为j的背包，最少钱币
        // 递推公式：dp[j]=min(dp[j-coins[i]]+1,dp[j])
        // 初始化：dp[0]=0，非零下标初始为INT_MAX
        // 遍历顺序：先遍历物品，再遍历背包，组合数；先遍历背包，后遍历物品，排列数；本题无所谓
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        zwn::outputIntArr(dp);
        for (int i = 0; i < coins.size(); ++i) {
            for (int j = coins[i]; j <= amount; ++j) {
                if (dp[j - coins[i]] == INT_MAX) {
                    continue;
                }
                dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
                zwn::outputIntArr(dp);
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

```




