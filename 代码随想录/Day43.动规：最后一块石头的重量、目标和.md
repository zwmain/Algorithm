# Day43.动规：最后一块石头的重量、目标和

## 1049.最后一块石头的重量II

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




## 0494.目标和

链接：[0494.目标和](https://leetcode.cn/problems/target-sum/)

把数分成两个集合，加法一个集合，减法一个集合

加法总和为left，减法总和为right

`left + right = sum`

`left - right = target`

解方程：`left=(target+sum)/2`

如果这里能整除，说明有结果，不能整除，说明没有结果

1. `dp[j]`含义：装满容量为j的背包，有`dp[j]`种方法
2. 递推公式：`dp[j]=dp[j]+dp[j-nums[i]]`
3. 初始化：`dp[0]=1`，当容量为0的时候，不放；如果取0的话，后面就都为0了
4. 遍历顺序：与01背包基本一致

```c++
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target)
    {
        // 把数分成两个集合，加法一个集合，减法一个集合
        // 加法总和为left，减法总和为right
        // left + right = sum
        // left - right = target
        // 解方程：left=(target+sum)/2
        // 如果这里能整除，说明有结果，不能整除，说明没有结果

        int sum = 0;
        for (int i : nums) {
            sum += i;
        }
        if ((target + sum) % 2 != 0) {
            return 0;
        }

        // dp[j]含义：装满容量为j的背包，有dp[j]种方法
        // 递推公式：dp[j]=dp[j]+dp[j-nums[i]]
        // 初始化：dp[0]=1，当容量为0的时候，不放；如果取0的话，后面就都为0了
        // 遍历顺序：与01背包基本一致
        int bagSize = (target + sum) / 2;
        vector<int> dp(bagSize + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = bagSize; j >= nums[i]; --j) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[bagSize];
    }
};

```




