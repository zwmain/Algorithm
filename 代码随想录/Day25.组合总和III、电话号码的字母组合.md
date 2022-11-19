# Day25.组合总和III、电话号码的字母组合

## 0216.组合总和III

链接：[0216.组合总和III](https://leetcode.cn/problems/combination-sum-iii/)

这题需要就是在0077那道题上加了个求和的限制

可以在函数开始判断当前和，如果当前和已经超过了目标值，那么直接剪枝

当path长度达到k时，还要再判断和是否达到目标值，才能加进结果数组


```c++
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        backtracking(k, n, 1);
        return _res;
    }

private:
    vector<vector<int>> _res;
    vector<int> _path;
    int _sum = 0;

    void backtracking(int k, int n, int ind)
    {
        if (_sum > n) {
            return;
        }
        if (_path.size() == k) {
            if (_sum == n) {
                _res.push_back(_path);
            }
            return;
        }
        // k是需要组合的总数量
        // path.size()是当前已经组合的数量
        // k-path.size()是还需要组合的数量
        // 那么 9 - (k - _path.size()) + 1 就是当前索引所能取到的最大限制
        for (int i = ind; i <= 9 - (k - _path.size()) + 1; ++i) {
            _path.push_back(i);
            _sum += i;
            backtracking(k, n, i + 1);
            _sum -= i;
            _path.pop_back();
        }
    }
};

```


## 0017.电话号码的字母组合

链接：[0017.电话号码的字母组合](https://leetcode.cn/problems/letter-combinations-of-a-phone-number/)

这题的各个字符串组是分开的，所以不用像之前那样使用ind标记走过的位置

这里的ind只代表输入字符串的索引

而对于组内的字符串，不需要去重


```c++
ass Solution {
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


