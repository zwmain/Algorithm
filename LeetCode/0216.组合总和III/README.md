# 0216.组合总和III

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


