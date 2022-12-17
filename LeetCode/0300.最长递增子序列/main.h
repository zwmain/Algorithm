#include "Utils.hpp"
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

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
