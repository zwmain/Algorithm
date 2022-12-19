#include "Utils.hpp"
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t)
    {
        if (s.size() < t.size()) {
            return 0;
        }
        if (t.empty()) {
            return 1;
        }
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for (int i = 0; i < dp.size(); ++i) {
            dp[i][0] = 1;
        }
        for (int j = 1; j < dp[0].size(); ++j) {
            dp[0][j] = 0;
        }
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 1; j <= t.size(); ++j) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        zwn::outputIntArrArr(dp);
        return dp.back().back();
    }
};
