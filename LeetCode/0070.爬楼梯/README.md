# 0070.爬楼梯

链接：[0070.爬楼梯](https://leetcode.cn/problems/climbing-stairs/)

当前位置可以从前一个楼梯爬1步上来，也可以从前两个楼梯爬2步上来，类似斐波那契
也就是说，爬到当前位置的方法等于前一个楼梯的方法加前两个楼梯的方法

动规思路：

1. 确定`dp[i]`：`dp[i]`就是第i个楼梯的方法
2. 递推公式：`dp[i]=dp[i-1]+dp[i-2]`
3. dp数组初始化：`d[1]=1, dp[2]=2, i>=1`
4. 遍历顺序：从前向后遍历

```c++
class Solution {
public:
    int climbStairs(int n)
    {
        if (n <= 2) {
            return n;
        }
        int a = 1;
        int b = 2;
        int res = 0;
        for (int i = 3; i <= n; ++i) {
            res = b + a;
            a = b;
            b = res;
        }
        return res;
    }
    int climbStairs1(int n)
    {
        if (n <= 2) {
            return n;
        }
        // 当前位置可以从前一个楼梯爬1步上来，也可以从前两个楼梯爬2步上来，类似斐波那契
        // 也就是说，爬到当前位置的方法等于前一个楼梯的方法加前两个楼梯的方法
        // 确定dp[i]：dp[i]就是第i个楼梯的方法
        // 递推公式：dp[i]=dp[i-1]+dp[i-2]
        // dp数组初始化：d[1]=1, dp[2]=2, i>=1
        // 遍历顺序：从前向后遍历
        vector<int> dp(n + 1);
        dp[0] = 0; // 无意义
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

```


