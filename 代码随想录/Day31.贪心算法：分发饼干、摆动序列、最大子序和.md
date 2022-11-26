# Day31.贪心算法：分发饼干、摆动序列、最大子序和

## 0455.分发饼干

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




## 0376.摆动序列

链接：[0376.摆动序列](https://leetcode.cn/problems/wiggle-subsequence/)

准备一个`preDiff`代表上一个差值`curDiff`代表当前差值，如果发现当前差值与前一个差值符合不相反，跳过。

如果相反，技术+1

```c++
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums)
    {
        if (nums.size() <= 1) {
            return nums.size();
        }
        int curDiff = 0; // 当前一对差值
        int preDiff = 0; // 前一对差值
        int result = 1; // 记录峰值个数，序列默认序列最右边有一个峰值
        for (int i = 0; i < nums.size() - 1; i++) {
            curDiff = nums[i + 1] - nums[i];
            // 出现峰值
            if ((curDiff > 0 && preDiff <= 0) || (preDiff >= 0 && curDiff < 0)) {
                result++;
                preDiff = curDiff;
            }
        }
        return result;
    }
};

```



## 0053.最大子序和

链接：[0053.最大子序和](https://leetcode.cn/problems/maximum-subarray/)

如果当前和小于0，那么只会让后面的数越来越小。在和小于0的时候，应该重置sum

```c++
class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        if (nums.empty()) {
            return 0;
        }
        int sum = nums[0];
        int maxVal = sum;
        for (int i = 1; i < nums.size(); ++i) {
            if (sum < 0) {
                // 这里必须重置为当前值，而不是0
                sum = nums[i];
            } else {
                sum += nums[i];
            }

            // 每次sum更新后，都要更新maxVal
            if (sum > maxVal) {
                maxVal = sum;
            }
        }
        return maxVal;
    }
};

```




