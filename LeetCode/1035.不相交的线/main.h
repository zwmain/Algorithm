#include "Utils.hpp"
#include <algorithm>
#include <array>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2)
    {
        // 本题与最长公共子序列一致
        if(nums1.empty()||nums2.empty()){
            return 0;
        }
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), 0));
        int val = 0;
        for (size_t i = 0; i < nums1.size(); ++i) {
            if (nums1[i] == nums2[0]) {
                val = 1;
            }
            dp[i][0] = val;
        }
        val = 0;
        for (size_t j = 0; j < nums2.size(); ++j) {
            if (nums1[0] == nums2[j]) {
                val = 1;
            }
            dp[0][j] = val;
        }
        for (size_t i = 1; i < nums1.size(); ++i) {
            for (size_t j = 1; j < nums2.size(); ++j) {
                if (nums1[i] == nums2[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp.back().back();
    }
};
