# 0452.用最少数量的箭引爆气球

链接：[0452.用最少数量的箭引爆气球](https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/)

从重叠区域最多的地方发射，用到的箭最少。

按区间左位置排序，从第二个区间开始判断，如果重叠，就扩展最小右边界；如果不重叠，箭支+1

```c++
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

```



