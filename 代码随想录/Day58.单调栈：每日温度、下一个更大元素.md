# Day58.单调栈：每日温度、下一个更大元素




## 0739.每日温度

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










## 0496.下一个更大元素I

链接：[0496.下一个更大元素I](https://leetcode.cn/problems/next-greater-element-i/)

参考：[代码随想录](https://programmercarl.com/0496.下一个更大元素I.html)

```c++
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        stack<int> st;
        vector<int> result(nums1.size(), -1);
        if (nums1.size() == 0) {
            return result;
        }

        unordered_map<int, int> umap; // key:下标元素，value：下标
        for (int i = 0; i < nums1.size(); i++) {
            umap[nums1[i]] = i;
        }
        st.push(0);
        for (int i = 1; i < nums2.size(); i++) {
            if (nums2[i] < nums2[st.top()]) { // 情况一
                st.push(i);
            } else if (nums2[i] == nums2[st.top()]) { // 情况二
                st.push(i);
            } else { // 情况三
                while (!st.empty() && nums2[i] > nums2[st.top()]) {
                    if (umap.count(nums2[st.top()]) > 0) { // 看map里是否存在这个元素
                        int index = umap[nums2[st.top()]]; // 根据map找到nums2[st.top()] 在 nums1中的下标
                        result[index] = nums2[i];
                    }
                    st.pop();
                }
                st.push(i);
            }
        }
        return result;
    }
};

```









