# 0739.每日温度

链接：[0739.每日温度](https://leetcode.cn/problems/daily-temperatures/)

参考：[代码随想录](https://programmercarl.com/0739.每日温度.html)

```c++
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        // 递增栈
        stack<int> st;
        vector<int> result(temperatures.size(), 0);
        st.push(0);
        for (int i = 1; i < temperatures.size(); i++) {
            if (temperatures[i] < temperatures[st.top()]) { // 情况一
                st.push(i);
            } else if (temperatures[i] == temperatures[st.top()]) { // 情况二
                st.push(i);
            } else {
                while (!st.empty() && temperatures[i] > temperatures[st.top()]) { // 情况三
                    result[st.top()] = i - st.top();
                    st.pop();
                }
                st.push(i);
            }
        }
        return result;
    }
};

```









