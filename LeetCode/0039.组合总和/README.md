# 0039.组合总和

链接：[0039.组合总和](https://leetcode.cn/problems/combination-sum/)

这题的终止条件是sum值与目标值是否相等。如果sum大于目标，则直接终止递归；如果等于则收集结果，结束递归；如果小于目标则继续递归。

由于元素可以重复，那么下次递归的起始索引就可以从当前所以开始，而不用+1

```c++
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        backtracking(candidates, target, 0, 0);
        return _res;
    }

private:
    vector<vector<int>> _res;
    vector<int> _path;

    void backtracking(const vector<int> candidates, const int target, int sum, int ind)
    {
        if (sum > target) {
            return;
        } else if (sum == target) {
            _res.push_back(_path);
            return;
        } else {
            for (int i = ind; i < candidates.size(); ++i) {
                _path.push_back(candidates[i]);
                // 这里元素可以重复，所以下一层递归的索引可以和当前一样
                backtracking(candidates, target, sum + candidates[i], i);
                _path.pop_back();
            }
        }
    }
};

```

