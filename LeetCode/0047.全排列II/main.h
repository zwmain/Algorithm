#include "Utils.hpp"
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

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
