#include "Utils.hpp"
#include <algorithm>
#include <stack>
#include <string>
#include <vector>

using namespace std;

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
