# Day38.动规：斐波那契、爬楼梯、最小代价爬楼梯


#3 0509.斐波那契数

链接：[0509.斐波那契数](https://leetcode.cn/problems/fibonacci-number/)

借助简单的例子理解动规原理：

1. 确定`dp[i]`含义：`dp[i]`就是第i个斐波那契数的值
2. 递推公式：`dp[i]=dp[i-1]+dp[i-2]`
3. dp数组如何初始化：`dp[0]=0, dp[1]=1`
4. 遍历顺序：从前往后遍历
5. 打印dp数组，方便调试

由于只需要当前值的前两个值，所以并不需要一个数组，维护两个变量就可以了

```cpp
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



## 0070.爬楼梯

链接：[0070.爬楼梯](https://leetcode.cn/problems/climbing-stairs/)

当前位置可以从前一个楼梯爬1步上来，也可以从前两个楼梯爬2步上来，类似斐波那契
也就是说，爬到当前位置的方法等于前一个楼梯的方法加前两个楼梯的方法

动规思路：

1. 确定`dp[i]`：`dp[i]`就是第i个楼梯的方法
2. 递推公式：`dp[i]=dp[i-1]+dp[i-2]`
3. dp数组初始化：`d[1]=1, dp[2]=2, i>=1`
4. 遍历顺序：从前向后遍历

```cpp
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



## 0746.使用最小花费爬楼梯

链接：[0746.使用最小花费爬楼梯](https://leetcode.cn/problems/min-cost-climbing-stairs/)

1. `dp[i]`的含义：爬到第i个楼梯的最小开销
2. 递推公式：`dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2])`
3. dp数组初始化：最开始是可选择站在0,1位置上，即第一个第二个台阶，`dp[0]=1, dp[1]=0`
4. 遍历顺序：从前向后遍历

```cpp
class Solution {
public:
    int minCostClimbingStairs1(vector<int>& cost)
    {
        if (cost.size() < 2) {
            return 0;
        }
        // dp[i]的含义：爬到第i个楼梯的最小开销
        // 递推公式：dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2])
        // dp数组初始化：最开始是可选择站在0,1位置上，即第一个第二个台阶，dp[0]=1, dp[1]=0
        // 遍历顺序：从前向后遍历
        vector<int> dp(cost.size() + 1);
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <= cost.size(); ++i) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp.back();
    }
    int minCostClimbingStairs(vector<int>& cost)
    {
        if (cost.size() < 2) {
            return 0;
        }
        int a = 0;
        int b = 0;
        int res = 0;
        for (int i = 2; i <= cost.size(); ++i) {
            res = min(b + cost[i - 1], a + cost[i - 2]);
            a = b;
            b = res;
        }
        return res;
    }
};

```




