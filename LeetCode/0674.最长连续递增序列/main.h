#include "Utils.hpp"
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

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
