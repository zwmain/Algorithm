# 1049.最后一块石头的重量II

链接：[1049.最后一块石头的重量II](https://leetcode.cn/problems/last-stone-weight-ii/)

把石头分为两堆，让这两堆石头相撞，如果两边重量尽可能相似，那么结果就会最小

头总重量为N，那么尽可能凑N/2重量

类似01背包，这里的重量也是物品的价值，背包容量就是N/2

1. `dp[j]`含义：装满容量为j的背包，最大重量为`dp[j]`
2. 递推公式：`dp[j]=max(dp[j],dp[j-stones[i]]+stones[i])`
3. 初始化：和01背包一致，都初始化为0；dp数组为二分之总重量
4. 遍历顺序：与01背包一致


```c++
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones)
    {
        // 把石头分为两堆，让这两堆石头相撞，如果两边重量尽可能相似，那么结果就会最小
        // 石头总重量为N，那么尽可能凑N/2重量
        // 类似01背包，这里的重量也是物品的价值，背包容量就是N/2
        // dp[j]含义：装满容量为j的背包，最大重量为dp[j]
        // 递推公式：dp[j]=max(dp[j],dp[j-stones[i]]+stones[i])
        // 初始化：和01背包一致，都初始化为0；dp数组为二分之总重量
        int sumWeight = 0;
        for (int w : stones) {
            sumWeight += w;
        }
        int target = sumWeight / 2;
        vector<int> dp(target + 1, 0);
        for (int i = 0; i < stones.size(); ++i) {
            for (int j = dp.size() - 1; j >= stones[i]; --j) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        // 其中一堆石头重量是dp.back()，那么另一堆石头重量就是sumWeight-dp.back
        // 两堆石头再相减
        return sumWeight - dp.back() - dp.back();
    }
};

```



