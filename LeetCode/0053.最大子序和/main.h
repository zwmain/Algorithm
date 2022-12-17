#include "Utils.hpp"
#include <algorithm>
#include <climits>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        if (nums.empty()) {
            return 0;
        }
        int sum = nums[0];
        int maxVal = sum;
        for (int i = 1; i < nums.size(); ++i) {
            if (sum < 0) {
                sum = nums[i];
            } else {
                sum += nums[i];
            }

            if (sum > maxVal) {
                maxVal = sum;
            }
        }
        return maxVal;
    }
    int maxSubArray2(vector<int>& nums)
    {
        if (nums.empty()) {
            return 0;
        }
        // dp[i]：包括下标i之前的最大连续子序列和为dp[i]。
        // dp[i]只有两个方向可以推出来：
        // dp[i - 1] + nums[i]，即：nums[i]加入当前连续子序列和
        // nums[i]，即：从头开始计算当前连续子序列和
        // 一定是取最大的，所以dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        // 从递推公式可以看出来dp[i]是依赖于dp[i - 1]的状态，dp[0]就是递推公式的基础。dp[0] = nums[0]
        // 递推公式中dp[i]依赖于dp[i - 1]的状态，需要从前向后遍历。
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int result = dp[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            if (dp[i] > result) {
                result = dp[i];
            }
        }
        return result;
    }
};
