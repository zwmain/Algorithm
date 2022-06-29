# 0303.区域和检索-数组不可变

链接：[0303.区域和检索-数组不可变](https://leetcode.cn/problems/range-sum-query-immutable/)

## 我的解法

每次调用`sumRange`的时候，从`left`遍历到`right`，闭区间求和

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

## labuladong的解法：“前缀和”数组

准备一个“前缀和”数组，为方便计算，“前缀和”数组第一个值为0，大小为`nums`大小加1

“前缀和”数组中，第i个值的含义是：`nums`数组\[0, i\)的和

当需要\[left, right\]区间和的时候，就相当于是\[0, right+1\)区间减去\[0, left\)区间

即：`_pre[right + 1] - _pre[left]`

## 源码

```c++
class NumArray {
public:
    NumArray(vector<int>& nums)
        : _nums(nums)
    {
        _pre.resize(_nums.size() + 1);
        _pre[0] = 0;
        for (size_t i = 1; i < _pre.size(); ++i) {
            _pre[i] = _pre[i - 1] + _nums[i - 1];
        }
    }

    int sumRange(int left, int right)
    {
        return _pre[right + 1] - _pre[left];
    }

private:
    vector<int>& _nums;
    vector<int> _pre;
};

```
