# 0494.目标和

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




