# 0349.两个数组的交集

链接：[0349.两个数组的交集](https://leetcode.cn/problems/intersection-of-two-arrays/)

思路：借助集合，统计第一个数组中的数，然后遍历第二个数组，如果集合中有这个数，则添加到交集中，然后从集合中移除这个数，继续遍历。

```c++
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        set<int> repeat;
        for (int i : nums1) {
            repeat.insert(i);
        }
        vector<int> res;
        for (int i : nums2) {
            auto it = repeat.find(i);
            if (it != repeat.end()) {
                res.push_back(i);
                repeat.erase(it);
            }
        }
        return res;
    }
};

```
