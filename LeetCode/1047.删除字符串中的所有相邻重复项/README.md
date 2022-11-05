# 1047.删除字符串中的所有相邻重复项

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
