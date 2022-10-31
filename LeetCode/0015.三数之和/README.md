# 0015.三数之和

链接：[0015.三数之和](https://leetcode.cn/problems/3sum/submissions/)

思路：题目要求返回数组的值，并且要求元组不能重复，为了方便去除重复，先将数组排序。排序后就容易确定a,b,c的顺序，分别将它们和自己相邻的数比较，如果重复就跳过，因为是排了序的，相同的值一定相邻。

指定一个指针始终代表最左边的数，然后再设置两个指针指向剩余区间的最左边和最右边。
就向滑动窗口那样通过窗口收缩，寻找和为0的情况。
如果和为0，收集结果，一定要先收集结果。然后开始去重left和right，left向右，right向左，跳过所有相同值，然后收缩区间。
当一轮结束后，i左移一位。

```c++
class Solution {
public:
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

```
