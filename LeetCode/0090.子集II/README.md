# 0090.子集II

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
