#include "Utils.hpp"
#include <string>
#include <vector>

using namespace std;

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
