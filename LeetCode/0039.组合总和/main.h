#include "Utils.hpp"
#include <string>
#include <vector>

using namespace std;

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
