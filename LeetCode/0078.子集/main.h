#include "Utils.hpp"
#include <string>
#include <vector>

using namespace std;

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
