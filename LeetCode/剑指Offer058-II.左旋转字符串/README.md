# 剑指Offer058-II.左旋转字符串

链接：[剑指Offer058-II.左旋转字符串](https://leetcode.cn/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/)

思路：这题当时老师交过我们一次，我的印象非常深刻。先逆序前半部分，再逆序后半部分，最后整个逆序，就可以达到效果了。

```c++
class Solution {
public:
    string reverseLeftWords(string s, int n)
    {
        // 逆序前半部分
        reverse(s, 0, n - 1);
        // 逆序后半部分
        reverse(s, n, s.size() - 1);
        // 整个逆序
        reverse(s, 0, s.size() - 1);
        return s;
    }
    void reverse(string& s, int left, int right)
    {
        if (right >= s.size()) {
            return;
        }
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
