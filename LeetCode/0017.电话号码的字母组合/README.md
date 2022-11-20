# 0017.电话号码的字母组合

链接：[0017.电话号码的字母组合](https://leetcode.cn/problems/letter-combinations-of-a-phone-number/)

这题的各个字符串组是分开的，所以不用像之前那样使用ind标记走过的位置

这里的ind只代表输入字符串的索引

而对于组内的字符串，不需要去重


```c++
class Solution {
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty()) {
            return _res;
        }
        backtracking(digits, 0);
        return _res;
    }

private:
    string _s;
    vector<string> _res;
    const string _keyMap[10] = {
        "", // 0
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz", // 9
    };

    void backtracking(const string& digits, int ind)
    {
        if (ind == digits.size()) {
            _res.push_back(_s);
            return;
        }
        int num = digits[ind] - '0';
        for (size_t i = 0; i < _keyMap[num].size(); ++i) {
            _s.push_back(_keyMap[num][i]);
            backtracking(digits, ind + 1);
            _s.pop_back();
        }
    }
};

```


