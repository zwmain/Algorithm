# Day52.动规：最长递增子序列、最长连续递增子序列




## 0300.最长递增子序列

链接：[0300.最长递增子序列](https://leetcode.cn/problems/longest-increasing-subsequence/)

1. `dp[i]`表示i之前包括i的以`nums[i]`结尾最长上升子序列的长度
2. 位置i的最长升序子序列等于j从0到`i-1`各个位置的最长升序子序列 + 1 的最大值。所以：`if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1)`
3. 初始化：每一个i，对应的`dp[i]`（即最长上升子序列）起始大小至少都是1
4. `dp[i]` 是有0到`i-1`各个位置的最长升序子序列 推导而来，那么遍历i一定是从前向后遍历。j其实就是0到`i-1`，遍历i的循环在外层，遍历j则在内层

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        // dp[i]表示i之前包括i的以nums[i]结尾最长上升子序列的长度
        // 位置i的最长升序子序列等于j从0到i-1各个位置的最长升序子序列 + 1 的最大值。
        // 所以：if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1)
        // 初始化：每一个i，对应的dp[i]（即最长上升子序列）起始大小至少都是1
        // dp[i] 是有0到i-1各个位置的最长升序子序列 推导而来，那么遍历i一定是从前向后遍历。j其实就是0到i-1，遍历i的循环在外层，遍历j则在内层
        if (nums.empty()) {
            return 0;
        }
        vector<int> dp(nums.size(), 1);
        int result = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if (dp[i] > result) {
                result = dp[i];
            }
        }
        return result;
    }
};

```





## 0674.最长连续递增序列

链接：[0674.最长连续递增序列](https://leetcode.cn/problems/longest-continuous-increasing-subsequence/)

1. `dp[i]`，以`dp[i]`结尾的连续递增子序列长度
2. 递推公式：如果`nums[i]>nums[i-1]`，那么`dp[i]=dp[i-1]+1`，否则等于1
3. 初始化，默认全为1
4. 从前向后遍历

```cpp
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums)
    {
        if (nums.empty()) {
            return 0;
        }
        // dp[i]，以dp[i]结尾的连续递增子序列长度
        // 递推公式：如果nums[i]>nums[i-1]，那么dp[i]=dp[i-1]+1，否则等于1
        // 初始化，默认全为1
        // 从前向后遍历
        vector<int> dp(nums.size(), 1);
        int res = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            } else {
                dp[i] = 1;
            }
            if (dp[i] > res) {
                res = dp[i];
            }
        }
        return res;
    }
};

```




