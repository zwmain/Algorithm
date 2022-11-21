#include "Utils.hpp"
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        // 排序，方便去重
        sort(candidates.begin(), candidates.end());
        _used.resize(candidates.size());
        fill(_used.begin(), _used.end(), false);
        backtracking(candidates, target, 0, 0);
        return _res;
    }

private:
    vector<vector<int>> _res;
    vector<int> _path;
    vector<bool> _used;

    void backtracking(const vector<int>& candidates, const int target, int sum, int ind)
    {
        if (sum > target) {
            return;
        } else if (sum == target) {
            _res.push_back(_path);
            return;
        } else {
            for (int i = ind; i < candidates.size(); ++i) {
                // 去重，当前值和前面值相同
                // 并且，只有才前面值没有使用的状态下才能去重
                // 因为，这里只需要树层去重，而不需要树枝去重
                if (i > 0 && _used[i - 1] == false && candidates[i] == candidates[i - 1]) {
                    continue;
                }
                _path.push_back(candidates[i]);
                _used[i] = true;
                // 这里使用的是i+1
                backtracking(candidates, target, sum + candidates[i], i + 1);
                _used[i] = false;
                _path.pop_back();
            }
        }
    }

    void backtracking2(const vector<int>& candidates, const int target, int sum, int ind)
    {
        if (sum > target) {
            return;
        } else if (sum == target) {
            _res.push_back(_path);
            return;
        } else {
            for (int i = ind; i < candidates.size(); ++i) {
                // 去重，当前值和前面值相同
                // 并且，去重仅限在树层内，而不是树枝内
                // ind某种意义上代表了回溯二叉树的层数
                if (i > ind && candidates[i] == candidates[i - 1]) {
                    continue;
                }
                _path.push_back(candidates[i]);
                _used[i] = true;
                // 这里使用的是i+1
                backtracking2(candidates, target, sum + candidates[i], i + 1);
                _used[i] = false;
                _path.pop_back();
            }
        }
    }
};
