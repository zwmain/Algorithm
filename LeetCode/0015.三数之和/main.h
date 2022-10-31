#include "Utils.hpp"
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // 错误解法。元素值没有去重。
    vector<vector<int>> threeSum2(vector<int>& nums)
    {
        unordered_set<int> numAppeared;
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = numAppeared.find(nums[i]);
            if (it != numAppeared.end()) {
                continue;
            }
            for (int j = i + 1; j < nums.size(); ++j) {
                for (int k = j + 1; k < nums.size(); ++k) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (sum != 0) {
                        continue;
                    }
                    vector<int> arr = { nums[i], nums[j], nums[k] };
                    res.push_back(arr);
                    numAppeared.insert(nums[i]);
                }
            }
        }
        return res;
    }
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> res;
        // 因为返回的是值，所以索引并不重要，排序后会方便去重
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            // 如果最左面的值大于0，那么它后面的值一定大于0，不用再继续算下去了
            if (nums[i] > 0) {
                return res;
            }
            // i始终代表最左边那个数，如果i和前面一位重复，说明该情况出现过，跳过
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            // 因为题目要求三个数下标不能相同，所以这里不能取到
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum > 0) {
                    --right;
                } else if (sum < 0) {
                    ++left;
                } else {
                    vector<int> arr = { nums[i], nums[left], nums[right] };
                    res.push_back(arr);
                    // 对left和right去重
                    while (left < right) {
                        if (nums[left] == nums[left + 1]) {
                            ++left;
                        } else {
                            break;
                        }
                    }
                    while (left < right) {
                        if (nums[right] == nums[right - 1]) {
                            --right;
                        } else {
                            break;
                        }
                    }
                    // left和right收缩
                    --right;
                    ++left;
                }
            }
        }
        return res;
    }
};
