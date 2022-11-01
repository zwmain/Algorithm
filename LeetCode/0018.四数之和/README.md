# 0018.四数之和

链接：[0018.四数之和](https://leetcode.cn/problems/4sum/)

参考：[代码随想录](https://programmercarl.com/0018.%E5%9B%9B%E6%95%B0%E4%B9%8B%E5%92%8C.html)

做这题前一定要做**0015.三数之和**，要不然不理解

在做这道题的时候，犯了一些错误：
- 剪枝时，只有最外层循环可以直接return，内层只能break
- 对于求和，要使用`long long`，否则会溢出

思路：在三数之和的基础上，外面再套一层循环。最左面有两个指针分别控制区间，那么这两个指针在内部循环将会被视为一个整体。

```c++
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

```
