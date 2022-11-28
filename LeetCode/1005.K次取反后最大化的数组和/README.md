# 1005.K次取反后最大化的数组和

链接：[1005.K次取反后最大化的数组和](https://leetcode.cn/problems/maximize-sum-of-array-after-k-negations/)

尽可能把绝对值大的数变为正数，绝对值小的数变为负数

```c++
class Solution {
private:
    static bool cmp(int a, int b)
    {
        return abs(a) > abs(b);
    }

public:
    int largestSumAfterKNegations(vector<int>& nums, int k)
    {
        if (nums.empty()) {
            return 0;
        }
        // 把绝对值大的放到前面
        sort(nums.begin(), nums.end(), cmp);

        for (size_t i = 0; i < nums.size() && k > 0; ++i) {
            if (nums[i] < 0) {
                nums[i] = 0 - nums[i];
                --k;
            }
        }
        if (k > 0 && k % 2 == 1) {
            int v = nums.back();
            nums.back() = 0 - v;
        }
        int sum = 0;
        for (int i : nums) {
            sum += i;
        }
        return sum;
    }
};

```


