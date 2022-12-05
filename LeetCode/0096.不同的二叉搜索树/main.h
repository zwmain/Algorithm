#include "Utils.hpp"
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n)
    {
        // dp[i]的含义：由i个节点组成的二叉树的的情况
        // 以j为头节点，左边就有j-1个节点，右边有i-j个节点
        // 那么以j为头节点时，就有dp[j-1]*dp[i-j]个情况
        // dp[i]=sum(dp[j-1]*dp[i-j]),j=[1,i]
        // 初始化：dp[0]=1，空树也是二叉搜索树；
        // 遍历顺序：从1开始遍历，
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            dp[i] = 0;
            for (int j = 1; j <= i; ++j) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};
