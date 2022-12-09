#include "Utils.hpp"
#include <string>
#include <vector>

using namespace std;

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
    int climbStairs2(int n)
    {
        // 用完全背包思路解决爬楼梯问题
        // 一步一个台阶，两个台阶，三个台阶，.......，直到 m个台阶。有多少种不同的方法可以爬到楼顶
        // 1阶，2阶，.... m阶就是物品，楼顶就是背包。
        // 每一阶可以重复使用，例如跳了1阶，还可以继续跳1阶。
        // dp[i]：爬到有i个台阶的楼顶，有dp[i]种方法。
        // 递推公式为：dp[i] += dp[i - j]
        // 既然递归公式是 dp[i] += dp[i - j]，那么dp[0] 一定为1，dp[0]是递归中一切数值的基础所在，如果dp[0]是0的话，其他数值都是0了。
        // 外层是背包，内层是物品
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) { // 遍历背包
            for (int j = 1; j <= 2; j++) { // 遍历物品
                if (i - j >= 0)
                    dp[i] += dp[i - j];
            }
        }
        return dp[n];
    }
};
