# Day29.全排列、递增子序列

## 0491.递增子序列

链接：[0491.递增子序列](https://leetcode.cn/problems/increasing-subsequences/)

本题无法用排序去重，为了保证只在本层内去重，定义一个集合，局部变量，只在本层递归可见，将访问过的元素加入集合，下次遍历之前，判断集合。

```c++
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums)
    {
        backtracking(nums, 0);
        return _res;
    }

private:
    vector<vector<int>> _res;
    vector<int> _path;

    void backtracking(const vector<int>& nums, int startInd)
    {
        if (_path.size() > 1) {
            _res.push_back(_path);
        }
        // 注意这个set只负责本层
        // 不负责下一层
        // 不能放在成员变量里
        unordered_set<int> used;
        for (int i = startInd; i < nums.size(); ++i) {
            if ((!_path.empty() && _path.back() > nums[i])
                || used.find(nums[i]) != used.end()) {
                continue;
            }
            _path.push_back(nums[i]);
            used.insert(nums[i]);
            backtracking(nums, i + 1);
            _path.pop_back();
        }
    }
};

```


## 0046.全排列

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


## 0047.全排列II

链接：[0047.全排列II](https://leetcode.cn/problems/permutations-ii/)

可以借助排序去重，因为本就有`used`数组，所以直接判断当前值和前面值是否相等，并且同时前一个元素没有使用（树层），即可决定是否跳过。

```c++
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        _used.resize(nums.size());
        fill(_used.begin(), _used.end(), false);
        // 排序
        sort(nums.begin(), nums.end());
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
            if (_used[i] || (i > 0 && nums[i] == nums[i - 1] && !_used[i - 1])) {
                // 1. 元素已经使用过，跳过
                // 2. 当前元素和前面元素相同，且前面元素没使用（树层），跳过
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


