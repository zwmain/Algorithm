#include "Utils.hpp"
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    static bool cmp(const vector<int>& a, const vector<int>& b)
    {
        return a[0] < b[0];
    }

public:
    int findMinArrowShots(vector<vector<int>>& points)
    {
        if (points.empty()) {
            return 0;
        }
        sort(points.begin(), points.end(), cmp);
        int res = 1; // 至少需要一支箭
        // 从第二个气球开始
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > points[i - 1][1]) {
                // 当前左边界大于前一个右边界
                // 箭+1
                ++res;
            } else {
                // 扩展当前最小右边界
                points[i][1] = min(points[i - 1][1], points[i][1]);
            }
        }
        return res;
    }
};
