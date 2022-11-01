#include "Utils.hpp"
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size(); ++k) {
            // 如果k位置的值>=0那么说明往后只会越加越大
            // 此时大于target，那后面就没有必要看下去了
            if (nums[k] > target && nums[k] >= 0) {
                // 这里可以是return也可以是break
                return res;
            }
            // 对k去重
            if (k > 0 && nums[k] == nums[k - 1]) {
                continue;
            }

            // 下面就和“三数之和”很像
            for (int i = k + 1; i < nums.size(); ++i) {
                // 这里需要把i,k的值看作一个整体
                const long long int twoSum = nums[k] + nums[i];
                // 如果i,k整体大于0，那么往后会越来越大
                // 此时大于target，后面就没有必要看了
                if (twoSum >= 0 && twoSum > target) {
                    break;
                    // 注意这里只能是break，不能返回
                    // return res;
                }
                // 对i去重
                if (i > k + 1 && nums[i] == nums[i - 1]) {
                    continue;
                }

                int left = i + 1;
                int right = nums.size() - 1;
                while (left < right) {
                    const long long int sum = twoSum + nums[left] + nums[right];
                    if (sum > target) {
                        --right;
                    } else if (sum < target) {
                        ++left;
                    } else {
                        res.push_back({ nums[k], nums[i], nums[left], nums[right] });
                        // left去重
                        while (left < right) {
                            if (nums[left] == nums[left + 1]) {
                                ++left;
                                continue;
                            } else {
                                break;
                            }
                        }
                        // right去重
                        while (left < right) {
                            if (nums[right] == nums[right - 1]) {
                                --right;
                                continue;
                            } else {
                                break;
                            }
                        }
                        // 窗口收缩
                        ++left;
                        --right;
                    }
                }
            }
        }
        return res;
    }
};
