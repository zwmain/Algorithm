#include "Utils.hpp"
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums)
    {
        // 包含下标i，偷的最大值为dp[i]，即[0,i]区间
        // 递推公式：偷i，dp[i-2]+nums[i]，i-1一定不能偷了；不偷i，dp[i-1]；这里只是考虑到区间范围，而不是一定偷或者不偷
        // 初始化：由于dp[i]依赖于i-1和i-2，因此必须初始化前2个dp。dp[0]=nums[0]，dp[1]=max(nums[0],nums[1])
        // 遍历顺序：从前向后
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        // zwn::outputIntArr(dp);
        for (int i = 2; i < dp.size(); ++i) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
            // zwn::outputIntArr(dp);
        }
        return dp[nums.size() - 1];
    }
};
