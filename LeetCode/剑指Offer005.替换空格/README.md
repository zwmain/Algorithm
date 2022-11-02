# 剑指Offer005.替换空格

链接：[剑指Offer005.替换空格](https://leetcode.cn/problems/reverse-string/)

思路：将数组扩容至替换后的大小，使用双指针，一个指向旧数组的最后一个元素，另一个指向新数组的最后一个元素。
如果左边的指针指的不是空格，那么直接将其移到新数组位置，两个指针同时前移。
如果左边指针指向空格，那么新数组指针填充"%20"并前移到空位，左指针跳过空格。
知道left到达字符串头或者right追上left时停止。

```c++
class Solution {
public:
    string replaceSpace(string s)
    {
        if (s.empty()) {
            return s;
        }
        int cnt = 0;
        for (char c : s) {
            if (c == ' ') {
                ++cnt;
            }
        }
        int left = s.size() - 1;
        if (cnt > 0) {
            s.append(2 * cnt, 'a');
        }
        int right = s.size() - 1;
        while (left >= 0 && right > left) {
            if (s[left] != ' ') {
                s[right] = s[left];
                --left;
                --right;
            } else {
                s[right] = '0';
                --right;
                s[right] = '2';
                --right;
                s[right] = '%';
                --right;
                --left;
            }
        }
        return s;
    }
};

```
