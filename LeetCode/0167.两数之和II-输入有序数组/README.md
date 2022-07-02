# 0167.两数之和II-输入有序数组

链接：[0167.两数之和II-输入有序数组](https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/)

## 我的解法

定义左右两个索引，`left`、`right`，`left`必须严格小于`right`

将数组的左右两数相加，如果与大于目标，则右索引-1；如果小于目标则左索引+1；如果等于目标，则结束

## 源码

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum > target) {
                --right;
            } else if (sum < target) {
                ++left;
            } else {
                break;
            }
        }
        return vector<int>({ left + 1, right + 1 });
    }
};

```
