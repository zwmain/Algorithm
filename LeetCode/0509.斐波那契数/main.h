#include "Utils.hpp"
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // 通过简单的例子理解动规原理
    int fib1(int n)
    {
        if (n <= 1) {
            return n;
        }
        // 确定dp[i]含义：dp[i]就是第i个斐波那契数的值
        // 递推公式：dp[i]=dp[i-1]+dp[i-2]
        // dp数组如何初始化：dp[0]=0, dp[1]=1
        // 遍历顺序：从前往后遍历
        // 打印dp数组，方便调试
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
    int fib(int n)
    {
        if (n <= 1) {
            return n;
        }
        int a = 0;
        int b = 1;
        int res = 0;
        for (int i = 2; i <= n; ++i) {
            res = b + a;
            a = b;
            b = res;
        }
        return res;
    }
};
