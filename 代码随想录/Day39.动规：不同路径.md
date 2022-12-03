# Day39.动规：不同路径


## 0062.不同路径

链接：[0062.不同路径](https://leetcode.cn/problems/unique-paths/)


1. `dp[i][j]`含义：走到i,j有多少种走法
2. 递推公式：只能向下或者向右，所以当前状态只能由上面和左边推到出来，`dp[i][j]=dp[i-1][j]+dp[i][j-1]`
3. 初始化：最上面和最左面必须初始化，`dp[0][j]=1,dp[i][0]=1`

```c++
class Solution {
public:
    int uniquePaths(int m, int n)
    {
        // dp[i][j]含义：走到i,j有多少种走法
        // 递推公式：只能向下或者向右，所以当前状态只能由上面和左边推到出来，dp[i][j]=dp[i-1][j]+dp[i][j-1]
        // 初始化：最上面和最左面必须初始化，dp[0][j]=1,dp[i][0]=1
        vector<vector<int>> dp(n, vector<int>(m));
        for (int j = 0; j < m; ++j) {
            dp[0][j] = 1;
        }
        for (int i = 0; i < n; ++i) {
            dp[i][0] = 1;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[n - 1][m - 1];
    }
};

```




## 0063.不同路径II

链接：[0063.不同路径II](https://leetcode.cn/problems/unique-paths-ii/)

1. `dp[i][j]`含义：走到i,j有多少种走法，如果i,j有障碍，则走法为0
2. 递推公式：只能向下或者向右，所以当前状态只能由上面和左边推到出来，如果当前位置没有障碍才推导`dp[i][j]=dp[i-1][j]+dp[i][j-1]`，否则直接为0
3. 初始化：最上面和最左面必须初始化，`dp[0][j]=1,dp[i][0]=1`，如果中间某一个有障碍，那么后面所有都为0
4. 遍历：从上到下，从左到右

```c++
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        // dp[i][j]含义：走到i,j有多少种走法，如果i,j有障碍，则走法为0
        // 递推公式：只能向下或者向右，所以当前状态只能由上面和左边推到出来
        // 如果当前位置没有障碍才推导dp[i][j]=dp[i-1][j]+dp[i][j-1]，否则直接为0
        // 初始化：最上面和最左面必须初始化，dp[0][j]=1,dp[i][0]=1，如果中间某一个有障碍，那么后面所有都为0
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size()));
        int val = 1;
        for (int i = 0; i < obstacleGrid.size(); ++i) {
            if (obstacleGrid[i][0] == 1) {
                val = 0;
            }
            dp[i][0] = val;
        }
        val = 1;
        for (int j = 0; j < obstacleGrid[0].size(); ++j) {
            if (obstacleGrid[0][j] == 1) {
                val = 0;
            }
            dp[0][j] = val;
        }
        for (int i = 1; i < obstacleGrid.size(); ++i) {
            for (int j = 1; j < obstacleGrid[0].size(); ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp.back().back();
    }
};

```



