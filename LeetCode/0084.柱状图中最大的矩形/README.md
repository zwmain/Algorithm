# 0084.柱状图中最大的矩形

链接：[0084.柱状图中最大的矩形][(https://leetcode.cn/problems/largest-rectangle-in-histogram/)

参考：[代码随想录](https://programmercarl.com/0084.柱状图中最大的矩形.html)

```c++
class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        stack<int> st;
        heights.insert(heights.begin(), 0); // 数组头部加入元素0
        heights.push_back(0); // 数组尾部加入元素0
        st.push(0);
        int result = 0;
        // 第一个元素已经入栈，从下标1开始
        for (int i = 1; i < heights.size(); i++) {
            // 注意heights[i] 是和heights[st.top()] 比较 ，st.top()是下标
            if (heights[i] > heights[st.top()]) {
                st.push(i);
            } else if (heights[i] == heights[st.top()]) {
                st.pop(); // 这个可以加，可以不加，效果一样，思路不同
                st.push(i);
            } else {
                while (heights[i] < heights[st.top()]) { // 注意是while
                    int mid = st.top();
                    st.pop();
                    int left = st.top();
                    int right = i;
                    int w = right - left - 1;
                    int h = heights[mid];
                    result = max(result, w * h);
                }
                st.push(i);
            }
        }
        return result;
    }
};


```









