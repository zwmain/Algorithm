# 0122.买卖股票的最佳时机II

链接：[0122.买卖股票的最佳时机II](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/)

贪心算法：

由于不能同时持有多只股票，那么买卖动作可以拆分为每一天。

比如第一天买进，第三天卖出，可以拆分为第一天买进，第二天卖出；第二天买进，第三天卖出。

那么为了保证最终结果最大，只要买间隔为正的股票就可以了。

动态规划：

1. `dp[i][0]`，第i天持有股票的最大现金；`dp[i][1]`第i天不持有股票的最大现金。持有不一定是买当天股票，只是保持着持有状态，有可能前面就买了；
2. 递推公式：对于`dp[i][0]`，当前i是持有的，有可能前面就买了，也有可能当天才买。如果前面就已经持有了，`dp[i][0]=dp[i-1][0]`，如果当前才买，那么现金前面不持有减去买当前股票的金额，`dp[i][0]=dp[i-1][1]-price[i]`。对于`dp[i][1]`，有可能前面已经卖了，也有可能当天才卖。`dp[i][1]=max(dp[i-1][1],dp[i-1][0]+prices[i])`
3. 初始化：`dp[0][0]=-prices[0],dp[0][1]=0`
4. 遍历顺序：从前向后


```c++
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int sum = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i - 1]) {
                sum += prices[i] - prices[i - 1];
            }
        }
        return sum;
    }

    int maxProfit2(vector<int>& prices)
    {
        // dp[i][0]，第i天持有股票的最大现金；dp[i][1]第i天不持有股票的最大现金
        // 持有不一定是买当天股票，只是保持着持有状态，有可能前面就买了；
        // 递推公式：对于dp[i][0]，当前i是持有的，有可能前面就买了，也有可能当天才买
        // 如果前面就已经持有了，dp[i][0]=dp[i-1][0]，如果当前才买，那么现金前面不持有减去买当前股票的金额，dp[i][0]=dp[i-1][1]-price[i]
        // 对于dp[i][1]，有可能前面已经卖了，也有可能当天才卖
        // dp[i][1]=max(dp[i-1][1],dp[i-1][0]+prices[i])
        // 初始化：dp[0][0]=-prices[0],dp[0][1]=0
        // 遍历顺序：从前向后
        vector<array<int, 2>> dp(prices.size(), { 0, 0 });
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < prices.size(); ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        return dp.back()[1];
    }
};

```

