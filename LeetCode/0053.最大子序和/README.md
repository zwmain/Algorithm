# 0053.最大子序和

链接：[0053.最大子序和](https://leetcode.cn/problems/maximum-subarray/)

如果当前和小于0，那么只会让后面的数越来越小。在和小于0的时候，应该重置sum

```c++
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
                // 这里必须重置为当前值，而不是0
                sum = nums[i];
            } else {
                sum += nums[i];
            }

            // 每次sum更新后，都要更新maxVal
            if (sum > maxVal) {
                maxVal = sum;
            }
        }
        return maxVal;
    }
};

```




