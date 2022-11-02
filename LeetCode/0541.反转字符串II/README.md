# 0541.反转字符串II

链接：[0541.反转字符串II](https://leetcode.cn/problems/reverse-string-ii/)

思路：每次反转多少字符，反转的左右区间是什么，是由剩余字符串长度决定的。即每次反转之前，需要判断当前i开始往后的字符串的长度，然后再决定反转区间。
每次反转过后，i+=2k。

```c++
class Solution {
public:
    string reverseStr(string s, int k)
    {
        int i = 0;
        for (; i < s.size(); i += 2 * k) {
            // 先计算剩余字符串长度
            // 然后根据剩余字符串长度决定反转多少字符
            int num = s.size() - i;
            if (num < k) {
                reverse(s, i, s.size() - 1);
            } else {
                reverse(s, i, i + k - 1);
            }
        }
        return s;
    }
    // 为了让代码逻辑更清晰，将纯反转字符串独立出来
    // 接收左闭右闭区间
    void reverse(string& s, int left, int right)
    {
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
