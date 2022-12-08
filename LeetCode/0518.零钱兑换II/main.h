#include "Utils.hpp"
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins)
    {
        // dp[j]含义：装满容量为j的背包，有dp[j]种方法，最终结果是dp[amount]
        // 递推公式：dp[j]=dp[j]+dp[j-conins[i]]
        // 初始化：dp[0]=1，保证递推后序的值有效
        // 遍历顺序，和01背包不同，完全背包遍历顺序为正序，因为可以重复使用
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < coins.size(); ++i) {
            for (int j = coins[i]; j <= amount; ++j) {
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};
