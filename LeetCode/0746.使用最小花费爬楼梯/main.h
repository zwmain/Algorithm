#include "Utils.hpp"
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs1(vector<int>& cost)
    {
        if (cost.size() < 2) {
            return 0;
        }
        // dp[i]的含义：爬到第i个楼梯的最小开销
        // 递推公式：dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2])
        // dp数组初始化：最开始是可选择站在0,1位置上，即第一个第二个台阶，dp[0]=1, dp[1]=0
        // 遍历顺序：从前向后遍历
        vector<int> dp(cost.size() + 1);
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <= cost.size(); ++i) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp.back();
    }
    int minCostClimbingStairs(vector<int>& cost)
    {
        if (cost.size() < 2) {
            return 0;
        }
        int a = 0;
        int b = 0;
        int res = 0;
        for (int i = 2; i <= cost.size(); ++i) {
            res = min(b + cost[i - 1], a + cost[i - 2]);
            a = b;
            b = res;
        }
        return res;
    }
};
