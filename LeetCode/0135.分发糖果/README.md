# 0135.分发糖果

链接：[0135.分发糖果](https://leetcode.cn/problems/candy/)

这道题目一定是要确定一边之后，再确定另一边，例如比较每一个孩子的左边，然后再比较右边，如果两边一起考虑一定会顾此失彼。

先确定右边评分大于左边的情况（也就是从前向后遍历）

此时局部最优：只要右边评分比左边大，右边的孩子就多一个糖果，全局最优：相邻的孩子中，评分高的右孩子获得比左边孩子更多的糖果

再确定左孩子大于右孩子的情况（从后向前遍历）

确定左孩子大于右孩子的情况一定要从后向前遍历！

如果 `ratings[i] > ratings[i + 1]`，此时`candyVec[i]`（第i个小孩的糖果数量）就有两个选择了，一个是`candyVec[i + 1] + 1`（从右边这个加1得到的糖果数量），一个是`candyVec[i]`（之前比较右孩子大于左孩子得到的糖果数量）。

```c++
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


