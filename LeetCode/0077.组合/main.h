#include "Utils.hpp"
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k)
    {
        backtracking(n, k, 1);
        return _res;
    }

private:
    vector<vector<int>> _res;
    vector<int> _path;

    void backtracking(int n, int k, int ind)
    {
        if (_path.size() == k) {
            _res.push_back(_path);
            return;
        }
        // 已经选择的元素个数：path.size();
        // 还需要的元素个数为: k - path.size();
        // 在集合n中，这一层范围最大可以取到: n - (k - path.size()) + 1
        for (int i = ind; i <= n - (k - _path.size()) + 1; ++i) {
            _path.push_back(i);
            backtracking(n, k, i + 1);
            _path.pop_back();
        }
    }
};

