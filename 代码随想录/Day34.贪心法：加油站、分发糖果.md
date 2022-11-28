# Day34.贪心法：加油站、分发糖果

## 1005.K次取反后最大化的数组和

链接：[1005.K次取反后最大化的数组和](https://leetcode.cn/problems/maximize-sum-of-array-after-k-negations/)

尽可能把绝对值大的数变为正数，绝对值小的数变为负数

```cpp
class Solution {
private:
    static bool cmp(int a, int b)
    {
        return abs(a) > abs(b);
    }

public:
    int largestSumAfterKNegations(vector<int>& nums, int k)
    {
        if (nums.empty()) {
            return 0;
        }
        // 把绝对值大的放到前面
        sort(nums.begin(), nums.end(), cmp);

        for (size_t i = 0; i < nums.size() && k > 0; ++i) {
            if (nums[i] < 0) {
                nums[i] = 0 - nums[i];
                --k;
            }
        }
        if (k > 0 && k % 2 == 1) {
            int v = nums.back();
            nums.back() = 0 - v;
        }
        int sum = 0;
        for (int i : nums) {
            sum += i;
        }
        return sum;
    }
};

```




## 0134.加油站

链接：[0134.加油站](https://leetcode.cn/problems/gas-station/)

如果总油量大于总消耗，那么一定可以跑完。那么单个站点的剩余油量可能大于或小于0，但是总和一定大于0。

从0累加**剩余油量**，和为`curSum`，如果`curSum`小于0，说明`[0,i]`都不能作为起始位置，起始位置需要从`i+1`重新算，`curSum`也要重新置为0。

同时，记录`totalSum`表示总剩余量，如果最后小于0，说明无法走完一圈

```C++
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int curSum = 0;
        int totalSum = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); ++i) {
            curSum += gas[i] - cost[i];
            totalSum += gas[i] - cost[i];
            if (curSum < 0) {
                start = i + 1;
                curSum = 0;
            }
        }
        if (totalSum < 0) {
            return -1;
        }
        return start;
    }
};

```




## 0135.分发糖果

链接：[0135.分发糖果](https://leetcode.cn/problems/candy/)

这道题目一定是要确定一边之后，再确定另一边，例如比较每一个孩子的左边，然后再比较右边，如果两边一起考虑一定会顾此失彼。

先确定右边评分大于左边的情况（也就是从前向后遍历）

此时局部最优：只要右边评分比左边大，右边的孩子就多一个糖果，全局最优：相邻的孩子中，评分高的右孩子获得比左边孩子更多的糖果

再确定左孩子大于右孩子的情况（从后向前遍历）

确定左孩子大于右孩子的情况一定要从后向前遍历！

如果 `ratings[i] > ratings[i + 1]`，此时`candyVec[i]`（第i个小孩的糖果数量）就有两个选择了，一个是`candyVec[i + 1] + 1`（从右边这个加1得到的糖果数量），一个是`candyVec[i]`（之前比较右孩子大于左孩子得到的糖果数量）。

```cpp
class Solution {
public:
    int candy(vector<int>& ratings)
    {
        vector<int> candyVec(ratings.size(), 1);
        // 从前向后
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                candyVec[i] = candyVec[i - 1] + 1;
            }
        }
        // 从后向前
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candyVec[i] = max(candyVec[i], candyVec[i + 1] + 1);
            }
        }
        // 统计结果
        int result = 0;
        for (int i = 0; i < candyVec.size(); i++) {
            result += candyVec[i];
        }
        return result;
    }
};

```


