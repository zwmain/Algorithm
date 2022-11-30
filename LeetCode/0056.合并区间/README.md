# 0056.合并区间

链接：[0056.合并区间](https://leetcode.cn/problems/merge-intervals/)

直接按照左边界排序，从第二个元素开始遍历，判断有无重叠。

如果重叠，扩大有边界，然后看下一个区间，直到没有重叠为止

```c++
class Solution {
private:
    static bool cmp(const vector<int>& a, const vector<int>& b)
    {
        return a[0] < b[0];
    }

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        vector<vector<int>> result;
        if (intervals.size() == 0) {
            return result;
        }
        sort(intervals.begin(), intervals.end(), cmp);
        bool flag = false; // 标记最后一个区间有没有合并
        int length = intervals.size();

        for (int i = 1; i < length; i++) {
            int start = intervals[i - 1][0]; // 初始为i-1区间的左边界
            int end = intervals[i - 1][1]; // 初始i-1区间的右边界
            while (i < length && intervals[i][0] <= end) { // 合并区间
                end = max(end, intervals[i][1]); // 不断更新右区间
                if (i == length - 1) {
                    flag = true; // 最后一个区间也合并了
                }
                i++; // 继续合并下一个区间
            }
            // start和end是表示intervals[i - 1]的左边界右边界，所以最优intervals[i]区间是否合并了要标记一下
            result.push_back({ start, end });
        }
        // 如果最后一个区间没有合并，将其加入result
        if (flag == false) {
            result.push_back({ intervals[length - 1][0], intervals[length - 1][1] });
        }
        return result;
    }
};

```



