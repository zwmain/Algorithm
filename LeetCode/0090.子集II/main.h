#include "Utils.hpp"
#include <string>
#include <vector>

using namespace std;

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
            // 树层去重
            if (i > startInd && nums[i] == nums[i - 1]) {
                continue;
            }
            _path.push_back(nums[i]);
            backtracking(nums, i + 1);
            _path.pop_back();
        }
    }
};
