# Day44.动规：零钱兑换II、组合总和IV


## 0518.零钱兑换II

链接：[0518.零钱兑换II](https://leetcode.cn/problems/coin-change-ii/)

这是一道典型的背包问题，一看到钱币数量不限，就知道这是一个完全背包。

注意题目描述中是凑成总金额的硬币组合数。

1. `dp[j]`含义：装满容量为j的背包，有`dp[j]`种方法，最终结果是`dp[amount]`
2. 递推公式：`dp[j]=dp[j]+dp[j-conins[i]]`
3. 初始化： `dp[0]=1`，保证递推后序的值有效
4. 遍历顺序，和01背包不同，完全背包遍历顺序为正序，因为可以重复使用

```cpp
class Solution {
public:
    int change(int amount, vector<int>& coins)
    {
        // dp[j]含义：装满容量为j的背包，有dp[j]种方法，最终结果是dp[amount]
        // 递推公式：dp[j]=dp[j]+dp[j-conins[i]]
        // 初始化：dp[0]=1，保证递推后序的值有效
        // 遍历顺序，和01背包不同，完全背包遍历顺序为正序，因为可以重复使用
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < coins.size(); ++i) {
            for (int j = coins[i]; j <= amount; ++j) {
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};

```







## 0377.组合总和Ⅳ

链接：[0377.组合总和Ⅳ](https://leetcode.cn/problems/combination-sum-iv/)

1. `dp[j]`含义：装满容量为j的背包，有`dp[j]`种方法，最终结果是`dp[target]`
2. 递推公式：`dp[j]=dp[j]+dp[j-nums[i]]`
3. 初始化：`dp[0]=1`，保证递推后序的值有效
4. 遍历顺序：先遍历背包，再遍历物品，得到排列数

```cpp
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target)
    {
        // dp[j]含义：装满容量为j的背包，有dp[j]种方法，最终结果是dp[target]
        // 递推公式：dp[j]=dp[j]+dp[j-nums[i]]
        // 初始化：dp[0]=1，保证递推后序的值有效
        // 遍历顺序：先遍历背包，再遍历物品，得到排列数
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int j = 0; j <= target; ++j) {
            for (int i = 0; i < nums.size(); ++i) {
                if (j - nums[i] >= 0 && dp[j] < INT_MAX - dp[j - nums[i]]) {
                    dp[j] += dp[j - nums[i]];
                }
            }
        }
        return dp[target];
    }
};

```





