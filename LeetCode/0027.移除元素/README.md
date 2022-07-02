# 0027.移除元素

链接：[0027.移除元素](https://leetcode.cn/problems/remove-duplicates-from-sorted-array/)

## 我的解法

设置一个索引，如果索引指向元素与目标值相同，那么就一直删除这个索引处的值

由于元素删除后，后续元素会前移，就相当于索引后移

那么删除动作就可以一直到索引越界或元素值不同时才退出

索引+1，继续操作

## 源码

```c++
class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        size_t ind = 0;
        while (ind < nums.size()) {
            while (ind < nums.size() && nums[ind] == val) {
                nums.erase(nums.begin() + ind);
            }
            ++ind;
        }
        return nums.size();
    }
};

```
