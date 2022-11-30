# Day36.无重叠区间、划分字母区间、合并区间



## 0435.无重叠区间

链接：[0435.无重叠区间](https://leetcode.cn/problems/non-overlapping-intervals/)

求解移除区间的最小数量，可以先求解非重叠区间的最大数量，然后总数减去这个数量，得到最终结果。

按照右边界排序，从左向右遍历

```cpp
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




## 0763.划分字母区间

链接：[0763.划分字母区间](https://leetcode.cn/problems/partition-labels/)

统计每一个字符最后出现的位置

从头遍历字符，并更新字符的最远出现下标，如果找到字符最远出现位置下标和当前下标相等了，则找到了分割点

```cpp
class Solution {
public:
    vector<int> partitionLabels(string s)
    {
        int hash[27] = { 0 }; // i为字符，hash[i]为字符出现的最后位置
        for (int i = 0; i < s.size(); i++) { // 统计每一个字符最后出现的位置
            hash[s[i] - 'a'] = i;
        }
        vector<int> result;
        int left = 0;
        int right = 0;
        for (int i = 0; i < s.size(); i++) {
            right = max(right, hash[s[i] - 'a']); // 找到字符出现的最远边界
            if (i == right) {
                result.push_back(right - left + 1);
                left = i + 1;
            }
        }
        return result;
    }
};

```




## 0056.合并区间

链接：[0056.合并区间](https://leetcode.cn/problems/merge-intervals/)

直接按照左边界排序，从第二个元素开始遍历，判断有无重叠。

如果重叠，扩大有边界，然后看下一个区间，直到没有重叠为止

```cpp
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



