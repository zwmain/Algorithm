# Day08.反转字符串、反转单词、替换空格

## 0344.反转字符串

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

## 0541.反转字符串II

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

## 剑指Offer005.替换空格

链接：[剑指Offer005.替换空格](https://leetcode.cn/problems/ti-huan-kong-ge-lcof/)

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

## 0151.反转字符串中的单词

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

## 剑指Offer058-II.左旋转字符串

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

