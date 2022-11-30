# 0435.无重叠区间

链接：[0435.无重叠区间](https://leetcode.cn/problems/non-overlapping-intervals/)

求解移除区间的最小数量，可以先求解非重叠区间的最大数量，然后总数减去这个数量，得到最终结果。

按照右边界排序，从左向右遍历

```c++
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
        // 按照右边界排序
        sort(intervals.begin(), intervals.end(), cmp);
        // 记录非交叉区间个数
        int cnt = 1;
        // 记录区间分割点
        int split = intervals[0][1];
        // 从左向右遍历
        for (int i = 1; i < intervals.size(); ++i) {
            if (split <= intervals[i][0]) {
                split = intervals[i][1];
                ++cnt;
            }
        }
        return intervals.size() - cnt;
    }
};

```



