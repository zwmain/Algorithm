#include "Utils.hpp"
#include <string>
#include <vector>

using namespace std;

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
