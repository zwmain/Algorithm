#include "Utils.hpp"
#include <numeric>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> res;
        res.resize(n);
        for (auto& arr : res) {
            arr.resize(n);
        }
        // 当前层数，可以表示当前层左上角的坐标
        int curLayer = 0;
        // 计数
        int ind = 1;
        int n2 = n * n;
        // 边长
        int len = n;
        while (ind <= n2) {
            int row = curLayer;
            int col = curLayer;
            // 向右
            for (int i = 0; i < len && ind <= n2; ++i) {
                res[row][col + i] = ind;
                ++ind;
            }
            col += len - 1;
            // 向下
            for (int i = 1; i < len && ind <= n2; ++i) {
                res[row + i][col] = ind;
                ++ind;
            }
            row += len - 1;
            // 向左
            for (int i = 1; i < len && ind <= n2; ++i) {
                res[row][col - i] = ind;
                ++ind;
            }
            col -= len - 1;
            // 向上
            for (row -= 1; row > curLayer && ind <= n2; --row) {
                res[row][col] = ind;
                ++ind;
            }
            // 缩圈
            // 边长减2
            len -= 2;
            // 当前层数加1
            ++curLayer;
        }
        return res;
    }
};
