# 0122.买卖股票的最佳时机II

链接：[0122.买卖股票的最佳时机II](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/)

由于不能同时持有多只股票，那么买卖动作可以拆分为每一天。

比如第一天买进，第三天卖出，可以拆分为第一天买进，第二天卖出；第二天买进，第三天卖出。

那么为了保证最终结果最大，只要买间隔为正的股票就可以了。

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
};

```


