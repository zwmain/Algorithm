# 0344.反转字符串

链接：[0344.反转字符串](https://leetcode.cn/problems/reverse-string/)

思路：从数组的两端开始，两两交换元素。这里使用闭区间，循环判断使用`<`

```c++
class Solution {
public:
    void reverseString(vector<char>& s)
    {
        if (s.empty()) {
            return;
        }
        size_t left = 0;
        size_t right = s.size() - 1;
        while (left < right) {
            char t = s[left];
            s[left] = s[right];
            s[right] = t;
            ++left;
            --right;
        }
    }
};

```
