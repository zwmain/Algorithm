# 0078.子集

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

