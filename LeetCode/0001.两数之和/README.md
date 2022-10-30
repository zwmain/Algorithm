# 0001.两数之和

链接：[0001.两数之和](https://leetcode.cn/problems/two-sum/)

思路：借助map，记录当前值和索引。每次计算target和当前值的差，查找这个差，如果查找到，说明这个差已经存在于数组中。当前值和差所对应的索引就是答案。

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> numMap;
        for (int i = 0; i < nums.size(); ++i) {
            int val = target - nums[i];
            auto it = numMap.find(val);
            if (it != numMap.end()) {
                return { it->second, i };
            }
            numMap.insert({ nums[i], i });
        }
        return { -1, -1 };
    }
};

```
