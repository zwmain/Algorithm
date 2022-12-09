# 0279.完全平方数

链接：[0279.完全平方数](https://leetcode.cn/problems/perfect-squares/)


把1、4、9、16、... 这些数当作物品，凑n

1. `dp[j]`，装满容量为j的背包，最少物品
2. 递推公式：`dp[j]=min(d[j-i*i]+1,dp[j])`
3. 初始化：`dp[0]=0`，非零下标初始为INT_MAX
4. 遍历顺序：先遍历物品，再遍历背包，组合数；先遍历背包，后遍历物品，排列数；本题无所谓

```c++
class Solution {
public:
    int numSquares(int n)
    {
        // 把1、4、9、16、... 这些数当作物品，凑n
        // dp[j]，装满容量为j的背包，最少物品
        // 递推公式：dp[j]=min(d[j-i*i]+1,dp[j])
        // 初始化：dp[0]=0，非零下标初始为INT_MAX
        // 遍历顺序：先遍历物品，再遍历背包，组合数；先遍历背包，后遍历物品，排列数；本题无所谓
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        zwn::outputIntArr(dp);
        for (int i = 1; i * i <= n; ++i) {
            for (int j = i * i; j <= n; ++j) {
                // 因为1也是完全平方数，所以一定有答案
                dp[j] = min(dp[j - i * i] + 1, dp[j]);
                zwn::outputIntArr(dp);
            }
        }
        return dp[n];
    }
};

```


