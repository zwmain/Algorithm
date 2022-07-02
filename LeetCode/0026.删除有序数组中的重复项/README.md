# 0026.删除有序数组中的重复项

链接：[0026.删除有序数组中的重复项](https://leetcode.cn/problems/remove-duplicates-from-sorted-array/)

## 我的解法

使用双指针

维护两个指针（索引），一个指向当前元素，给它起个名字叫慢指针；另一个去寻找相同的元素，给它起个名字叫快指针

每发现一个相同元素，即触发删除。此时数组元素前移，相当于快指针后移

当快指针走到元素与慢指针所指元素不同时，慢指针跳到快指针位置，循环，当索引超过数组长度时为止

## 源码

```c++
class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        size_t s = 0;
        size_t q = 0;
        while (s < nums.size()) {
            ++q;
            while (q < nums.size() && nums[s] == nums[q]) {
                nums.erase(nums.begin() + q);
            }
            s = q;
        }
        return nums.size();
    }
};

```
