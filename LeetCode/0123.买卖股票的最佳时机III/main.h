#include "Utils.hpp"
#include <algorithm>
#include <array>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        // dp数组含义：
        // dp[i][0]，第i天不操作的最大现金；dp[i][1]，第i天第一次持有股票；dp[i][2]，第i天第一次不持有；dp[i][3]，第二次持有；dp[i][4]，第二次不持有
        // 递推公式：
        // dp[i][0]=dp[i-1][0]
        // dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i])
        // dp[i][2]=max(dp[i-1][2],dp[i-1][1]+prices[i])
        // dp[i][3]=max(dp[i-1][3],dp[i-1][2]-prices[i])
        // dp[i][4]=max(dp[i-1][4],dp[i-1][3]+prices[i])
        // 其中，不操作的状态，是可以忽略的
        // 初始化：
        // dp[0][0]=0，dp[0][1]=-prices[0]，dp[0][2]=0，dp[0][3]=-prices[0]，dp[0][4]=0
        // 遍历顺序：从前向后
        vector<array<int, 4>> dp(prices.size(), { 0, 0, 0, 0 });
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = -prices[0];
        dp[0][3] = 0;
        for (int i = 1; i < prices.size(); ++i) {
            dp[i][0] = max(dp[i - 1][0], 0 - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] - prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] + prices[i]);
        }
        return dp.back()[3];
    }
};
