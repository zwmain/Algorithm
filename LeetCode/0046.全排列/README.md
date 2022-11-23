# 0046.全排列

链接：[0046.全排列](https://leetcode.cn/problems/permutations/)

排列是考虑顺序的，所以每次都要从数组头部开始遍历。另外还需要一个`used`数组标记元素是否用过。

```c++
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        _used.resize(nums.size());
        fill(_used.begin(), _used.end(), false);
        backtracking(nums);
        return _res;
    }

private:
    vector<vector<int>> _res;
    vector<int> _path;
    vector<bool> _used;

    void backtracking(const vector<int>& nums)
    {
        if (_path.size() == nums.size()) {
            _res.push_back(_path);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (_used[i]) {
                continue;
            }
            _used[i] = true;
            _path.push_back(nums[i]);
            backtracking(nums);
            _path.pop_back();
            _used[i] = false;
        }
    }
};

```


