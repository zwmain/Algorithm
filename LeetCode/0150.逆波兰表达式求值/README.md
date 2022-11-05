# 0150.逆波兰表达式求值

链接：[0150.逆波兰表达式求值](https://leetcode.cn/problems/evaluate-reverse-polish-notation/)

思路：借助栈。如果当前token是数字，入栈；如果是运算符，取出栈顶两个元素，计算，结果入栈。最后栈里剩余的就是结果。

```c++
class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<long long> st;
        for (auto& s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                long long num1 = st.top();
                st.pop();
                long long num2 = st.top();
                st.pop();
                if (s == "+") {
                    st.push(num2 + num1);
                }
                if (s == "-") {
                    st.push(num2 - num1);
                }
                if (s == "*") {
                    st.push(num2 * num1);
                }
                if (s == "/") {
                    st.push(num2 / num1);
                }
            } else {
                st.push(stoll(s));
            }
        }

        int result = static_cast<int>(st.top());
        return result;
    }
};

```
