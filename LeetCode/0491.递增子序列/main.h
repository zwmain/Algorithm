#include "Utils.hpp"
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

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
