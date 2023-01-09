#include "Utils.hpp"
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    static bool cmp(const vector<int>& a, const vector<int>& b)
    {
        return a[1] < b[1];
    }

public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals)
    {
        if (intervals.empty()) {
            return 0;
        }
        // 按照结束位置排序
        sort(intervals.begin(), intervals.end(), cmp);
        // 记录移除区间个数
        int cnt = 0;
        // 记录上一个保留区间的结束位置
        int end = intervals[0][1];
        // 从左向右遍历
        for (int i = 1; i < intervals.size(); ++i) {
            if (end <= intervals[i][0]) {
                // 区间不重叠
                end = intervals[i][1];
            } else {
                // 区间重叠
                ++cnt;
            }
        }
        return cnt;
    }
};
