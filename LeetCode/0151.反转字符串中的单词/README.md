# 0151.反转字符串中的单词

链接：[0151.反转字符串中的单词](https://leetcode.cn/problems/reverse-words-in-a-string/)

思路：

- 去除尾部空格
- 逆序，此时整个句子已经倒过来了，只需要将内部单词单独逆序，就可以实现目标效果
- 头部的空格已经被逆序到尾部，去除尾部空格
- 分单词逆序
  - 从第一个不为空格的字符开始，到之后第一个空格前的一个字符为止，就是一个单词，逆序
- 去除中间冗余空格
  - 寻找连续2以上的空格，寻找之后第一个不为空格的字符
  - 将后面的字符向前填充，后面的字符前移留下来的位置设置为空格
- 中间冗余空格去除后，尾部会留出空格，去除尾部空格

```c++
class Solution {
public:
    string reverseWords(string s)
    {
        // 去除尾部空格
        while (s[s.size() - 1] == ' ') {
            s.pop_back();
        }
        // 逆序
        reverse(s, 0, s.size() - 1);
        // 之前头部空格已经被逆序到尾部，去除空格
        while (s[s.size() - 1] == ' ') {
            s.pop_back();
        }
        // 分单词逆序
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                continue;
            }
            int j = i + 1;
            for (; j < s.size(); ++j) {
                if (s[j] == ' ') {
                    break;
                }
            }
            reverse(s, i, j - 1);
            i = j;
        }
        // 去重中间冗余空格
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') {
                continue;
            }
            // 如果i是空格，i+1不是空格，则不需要去除
            if (i + 1 < s.size() && s[i + 1] != ' ') {
                ++i;
                continue;
            }
            ++i; // 跳过一个空格
            // 寻找空格后第一个不为空格的字符
            int j = i + 1;
            for (; j < s.size(); ++j) {
                if (s[j] != ' ') {
                    break;
                }
            }
            // 将单词填充到前面的空格中，同时留下来的位置设置为空格
            while (j < s.size() && s[j] != ' ') {
                s[i] = s[j];
                s[j] = ' ';
                ++i;
                ++j;
            }
            // 由于for循环有一个++，因此这里--
            --i;
        }
        // 中间冗余空格去除后，有效字符前移，因此尾部会有空格，去除尾部空格
        while (s[s.size() - 1] == ' ') {
            s.pop_back();
        }
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
