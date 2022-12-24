# 0503.下一个更大元素II

链接：[0503.下一个更大元素II](https://leetcode.cn/problems/next-greater-element-ii/)

参考：[代码随想录](https://programmercarl.com/0503.下一个更大元素II.html)


```c++
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums)
    {
        vector<int> result(nums.size(), -1);
        if (nums.size() == 0) {
            return result;
        }
        stack<int> st;
        for (int i = 0; i < nums.size() * 2; i++) {
            // 模拟遍历两边nums，注意一下都是用i % nums.size()来操作
            while (!st.empty() && nums[i % nums.size()] > nums[st.top()]) {
                result[st.top()] = nums[i % nums.size()];
                st.pop();
            }
            st.push(i % nums.size());
        }
        return result;
    }
};

```








