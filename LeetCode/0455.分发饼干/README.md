# 0455.分发饼干

链接：[0455.分发饼干](https://leetcode.cn/problems/assign-cookies/)

对两个数组排序，那么饼干和需求数组的大值都在数组后面。

用当前最大的饼干尽可能满足最大的需求。

从后向前遍历g数组，寻找第一个满足`g[i]<=s.back()`的位置。

然后同时从后往前遍历两个数组。如果`g[i]<=s[j]`那么两个索引同时前移，否则只前移g数组

```c++
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s)
    {
        if (g.empty() || s.empty()) {
            return 0;
        }
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int childInd = 0;
        for (int i = g.size() - 1; i >= 0; --i) {
            int maxVal = s.back();
            if (maxVal >= g[i]) {
                childInd = i;
                break;
            }
        }

        int i = childInd;
        int j = s.size() - 1;
        int cnt = 0;
        while (i >= 0 && j >= 0) {
            if (s[j] >= g[i]) {
                ++cnt;
                --i;
                --j;
            } else {
                --i;
            }
        }
        return cnt;
    }
};

```




