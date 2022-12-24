# Day59.单调栈：接雨水、右边最大的数

## 0503.下一个更大元素II

链接：[0503.下一个更大元素II](https://leetcode.cn/problems/next-greater-element-ii/)

参考：[代码随想录](https://programmercarl.com/0503.下一个更大元素II.html)


```cpp
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









## 0042.接雨水

链接：[0042.接雨水](https://leetcode.cn/problems/next-greater-element-ii/)

参考：[代码随想录](https://programmercarl.com/0042.接雨水.html)

```cpp
class Solution {
public:
    int trap(vector<int>& height)
    {
        if (height.size() <= 2) {
            return 0; // 可以不加
        }
        stack<int> st; // 存着下标，计算的时候用下标对应的柱子高度
        st.push(0);
        int sum = 0;
        for (int i = 1; i < height.size(); i++) {
            if (height[i] < height[st.top()]) { // 情况一
                st.push(i);
            }
            if (height[i] == height[st.top()]) { // 情况二
                st.pop(); // 其实这一句可以不加，效果是一样的，但处理相同的情况的思路却变了。
                st.push(i);
            } else { // 情况三
                while (!st.empty() && height[i] > height[st.top()]) { // 注意这里是while
                    int mid = st.top();
                    st.pop();
                    if (!st.empty()) {
                        int h = min(height[st.top()], height[i]) - height[mid];
                        int w = i - st.top() - 1; // 注意减一，只求中间宽度
                        sum += h * w;
                    }
                }
                st.push(i);
            }
        }
        return sum;
    }
};

```









