# 0435.无重叠区间

链接：[0435.无重叠区间](https://leetcode.cn/problems/non-overlapping-intervals/)

在剩余区间无重叠的情况下，计算需要移除的最少区间，等价于计算可以保留的最多区间。

为了将保留的区间数量最大化，应保留结束位置最小的区间。

假设保留的区间中，结束位置最小的区间是`[start1,end1]`，其余保留的区间的结束位置都大于等于`end1`。
考虑区间`[start2,end2]`，其中`end2<end1`，则将区间`[start1,end1]`替换成`[start2,end2]`之后，
保留的区间仍然是无重叠的，且可以保留的区间一定不会更少。

根据上述分析，可以得到贪心策略：首先将区间按结束位置升序排序，
然后每次在剩余区间中选择结束位置最小的区间保留。
该贪心策略可以将保留的区间数量最大化，将移除的区间数量最小化。

具体做法是，将区间数组`intervals`按结束位置升序排序。

用`end`表示上一个保留区间的结束位置，初始时`end = intervals[0]`。从`intervals[1]`开始遍历。

对于区间`intervals[i]`：

- 如果`intervals[i][0]>=end`，说明不重叠，可以保留区间`intervals[i]`，`end`更新为`intervals[i][1]`。
- 如果`intervals[i][0]<end`，说明重叠，不能保留区间`intervals[i]`，`end`不变，移除区间数量+1。


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

```



