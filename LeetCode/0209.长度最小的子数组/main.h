#include "Utils.hpp"
#include <numeric>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        size_t slow = 0;
        size_t fast = 0;
        int minLen = numeric_limits<int>::max();
        int sum = 0;
        // 注意这里一定是fast做判断
        // fast先走，且每次只走1步
        while (fast < nums.size()) {
            // sum加上当前fast位置的值
            sum += nums[fast];
            // 慢指针移动，收缩窗口，每次收缩1步
            // 只要满足条件，窗口会一直收缩
            while (sum >= target) {
                int len = fast - slow + 1;
                if (len < minLen) {
                    minLen = len;
                }
                if (slow == fast) {
                    return 1;
                }
                // 收缩窗口
                sum -= nums[slow];
                ++slow;
            }
            // fast每次只后移1步
            ++fast;
        }
        return minLen == numeric_limits<int>::max() ? 0 : minLen;
    }
};
