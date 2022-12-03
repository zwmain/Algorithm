# 0509.斐波那契数

链接：[0509.斐波那契数](https://leetcode.cn/problems/fibonacci-number/)

借助简单的例子理解动规原理：

1. 确定`dp[i]`含义：`dp[i]`就是第i个斐波那契数的值
2. 递推公式：`dp[i]=dp[i-1]+dp[i-2]`
3. dp数组如何初始化：`dp[0]=0, dp[1]=1`
4. 遍历顺序：从前往后遍历
5. 打印dp数组，方便调试

由于只需要当前值的前两个值，所以并不需要一个数组，维护两个变量就可以了

```c++
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

```


