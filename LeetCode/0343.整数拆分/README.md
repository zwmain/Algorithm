# 0343.整数拆分

链接：[0343.整数拆分](https://leetcode.cn/problems/integer-break/)

1. `dp[i]`的含义：i拆分的最大乘积
2. 从1遍历到j，一个可能最大乘积是`j*(i-j)`，相当于拆分两个数；另一个是`j*dp[i-j]`相当于对`i-j`又做了拆分
3. 初始化：`dp[0]=0,dp[1]=0,dp[2]=1`，0和1都是无意义的
4. 遍历顺序：从3开始遍历，内层遍历从1开始，同时小于等于`i/2`

```c++
class Solution {
public:
    int integerBreak(int n)
    {
        // dp[i]的含义：i拆分的最大乘积
        // 递推公式：dp[i]=max(j*dp[i-j],j*(i-j)),j<i
        // 初始化：dp[0]=0,dp[1]=0,dp[2]=1，0和1都是无意义的
        // 遍历顺序：从3开始遍历，内层遍历从1开始，同时小于等于i/2
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 1;
        for (int i = 3; i <= n; ++i) {
            for (int j = 1; j <= i / 2; ++j) {
                dp[i] = max({ dp[i], j * (i - j), j * dp[i - j] });
            }
        }
        return dp[n];
    }
};

```


