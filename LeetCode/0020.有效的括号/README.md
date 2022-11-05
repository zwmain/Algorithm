# 0020.有效的括号

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
