# 0242.有效的字母异位词

链接：[0242.有效的字母异位词](https://leetcode.cn/problems/valid-anagram/)

思路：由于只包含小写字母，可以借助计数判断元素是否重复。建立一个26大小的数组，对于第一个字符串，每个字符对应的计数加1；第二个字符串，每个字符减1。
如果最后数组中都是0，那么就说明两个字符串中的字符一致。

```c++
class Solution {
public:
    bool isAnagram(string s, string t)
    {
        vector<int> cntArr(26);
        for (size_t i = 0; i < cntArr.size(); ++i) {
            cntArr[i] = 0;
        }
        for (char c : s) {
            cntArr[c - 'a'] += 1;
        }
        for (char c : t) {
            cntArr[c - 'a'] -= 1;
        }
        for (size_t i = 0; i < 26; ++i) {
            if (cntArr[i] != 0) {
                return false;
            }
        }
        return true;
    }
};

```
