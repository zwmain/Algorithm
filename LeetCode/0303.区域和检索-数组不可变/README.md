# 0303.区域和检索-数组不可变

链接：[0303.区域和检索-数组不可变](https://leetcode.cn/problems/range-sum-query-immutable/)

## 我的解法

## 源码

```c++
class NumArray {
public:
    NumArray(vector<int>& nums)
        : _nums(nums)
    {
    }

    int sumRange(int left, int right)
    {
        int cnt = 0;
        for (int i = left; i <= right; ++i) {
            cnt += _nums[i];
        }
        return cnt;
    }

private:
    vector<int>& _nums;
};

```
