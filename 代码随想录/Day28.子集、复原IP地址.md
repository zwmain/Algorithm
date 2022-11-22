# Day28.子集、复原IP地址

## 0093.复原IP地址

链接：[0093.复原IP地址](https://leetcode.cn/problems/restore-ip-addresses/)

IP地址为4段，我们只需要分出前3段，那么最后剩下的所有字符串为最后一段

分割字符串可以借助`startInd`和当前i的值，因为是IP，所以字符数量不会大于3，可以提前结束循环。

```c++
class Solution {
public:
    vector<string> restoreIpAddresses(string s)
    {
        backtracking(s, 0);
        return _res;
    }

private:
    vector<string> _res;
    vector<string> _path;

    void backtracking(const string& s, int startInd)
    {
        // 当path里有3组时，就可以判断了
        // 因为剩下的所有字符串为最后一组
        if (_path.size() == 3) {
            if (startInd >= s.size()) {
                return;
            }
            // 截取最后所有字符串
            string t = s.substr(startInd, s.size() - startInd);
            // 如果最后一段不是IP，那么直接返回
            if (!isIpNum(t)) {
                return;
            }
            string ip;
            for (auto& i : _path) {
                ip += i;
                ip.push_back('.');
            }
            ip += t;
            _res.push_back(ip);
            return;
        }
        for (int i = startInd; i < s.size() && i - startInd < 3; ++i) {
            string t = s.substr(startInd, i - startInd + 1);
            if (!isIpNum(t)) {
                continue;
            }
            _path.push_back(t);
            backtracking(s, i + 1);
            _path.pop_back();
        }
    }

    bool isIpNum(const string& s)
    {
        if (s.size() > 3) {
            return false;
        }
        if (s[0] == '0' && s.size() != 1) {
            return false;
        }
        int val = stoi(s);
        if (val < 0 || val > 255) {
            return false;
        }
        return true;
    }
};

```


## 0078.子集

链接：[0078.子集](https://leetcode.cn/problems/subsets/)

所有子集都是组合的结果，在前面的组合问题中，都是满足一定条件才收集结果，而子集则是每次都收集结果

```c++
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        backtracking(nums, 0);
        return _res;
    }

private:
    vector<vector<int>> _res;
    vector<int> _path;

    void backtracking(const vector<int>& nums, int startInd)
    {
        _res.push_back(_path);
        for (int i = startInd; i < nums.size(); ++i) {
            _path.push_back(nums[i]);
            backtracking(nums, i + 1);
            _path.pop_back();
        }
    }
};

```


## 0090.子集II

链接：[0090.子集II](https://leetcode.cn/problems/subsets-ii/)

涉及到去重，提前排序，将相同值集中在一起。

需要在树层去重，startInd由于是每深一层就+1，所以可以代表数层。当i>startInd时，如果当前值等于前面值，直接跳过。

这题与**0040.组合总和II**的去重思路一致

```c++
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        // 为了去重，需要排序
        sort(nums.begin(), nums.end());
        backtracking(nums, 0);
        return _res;
    }

private:
    vector<vector<int>> _res;
    vector<int> _path;

    void backtracking(const vector<int>& nums, int startInd)
    {
        _res.push_back(_path);
        for (int i = startInd; i < nums.size(); ++i) {
            if (i > startInd && nums[i] == nums[i - 1]) {
                continue;
            }
            _path.push_back(nums[i]);
            backtracking(nums, i + 1);
            _path.pop_back();
        }
    }
};

```
