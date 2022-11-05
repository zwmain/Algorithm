# Day11.逆波兰表达式求值、有效括号

## 0020.有效的括号

链接：[0020.有效的括号](https://leetcode.cn/problems/valid-parentheses/)

思路：使用一个栈，遍历字符串。如果栈为空就直接将字符加入。如果不为空，判断字符是左字符还是右字符。
如果是左字符，直接加入；如果是右字符，判断与栈顶字符是否匹配，若不匹配，直接返回false，若匹配则移除栈顶。
循环直到字符串遍历完毕。

最后如果栈为空，说明括号有效。

```c++
class Solution {
public:
    bool isValid(string s)
    {
        if (s.size() % 2 != 0) {
            return false;
        }
        stack<char> stk;
        for (auto c : s) {
            if (stk.empty()) {
                stk.push(c);
            } else {
                char e = 0;
                if (c == ')') {
                    e = '(';
                } else if (c == ']') {
                    e = '[';
                } else if (c == '}') {
                    e = '{';
                } else {
                    stk.push(c);
                    continue;
                }
                char t = stk.top();
                if (e == t) {
                    stk.pop();
                } else {
                    return false;
                }
            }
        }
        return stk.empty();
    }
};

```

## 1047.删除字符串中的所有相邻重复项

链接：[1047.删除字符串中的所有相邻重复项](https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/)

思路：借助栈，遍历字符串。如果栈顶字符和当前字符一致，直接pop；否则入栈。

这里可以借助`std::string`的`back`和`push_back`、`pop_back`模拟一个栈

```c++
class Solution {
public:
    string removeDuplicates(string s)
    {
        string stk;
        for (auto c : s) {
            if (stk.empty()) {
                stk.push_back(c);
            } else {
                char t = stk.back();
                if (t == c) {
                    stk.pop_back();
                } else {
                    stk.push_back(c);
                }
            }
        }
        return stk;
    }
};

```

## 0150.逆波兰表达式求值

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

