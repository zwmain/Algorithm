# 0977.有序数组的平方

链接：[0977.有序数组的平方](https://leetcode.cn/problems/squares-of-a-sorted-array/)

思路1：双指针法，从两边向中间。数组是有序的，绝对值大的数都在两边。由于结果要求从小到大，所以新数组从后往前填。

```c++
class Solution {
public:
    // 双指针法，从两边向中间，更加简单
    // 数组是有序的，绝对值大的数都在两边
    // 由于结果要求从小到大，所以新数组从后往前填
    vector<int> sortedSquares(vector<int>& nums)
    {
        size_t left = 0;
        size_t right = nums.size() - 1;
        vector<int> res(nums.size());
        size_t ind = res.size() - 1;
        // [left,right]为闭区间，所以这里为<=
        while (left <= right) {
            if (abs(nums[left]) >= abs(nums[right])) {
                res[ind] = nums[left] * nums[left];
                ++left;
            } else {
                res[ind] = nums[right] * nums[right];
                --right;
            }
            --ind;
        }
        return res;
    }
};

```

思路2：也是双指针法，只不过是从中间向两边，较为麻烦。多了一个寻找最小绝对值的过程，这里容易出错。不过数组是从小到大添加进去的。寻找到最小绝对值后，先将其添加到数组中。
然后从最小绝对值的两边开始，两个指针分别移动。这里还会出现其中一个指针不合法的情况，需要考虑进去，增加了逻辑的复杂度。

```c++
class Solution {
public:
    // 双指针法，从中间向两边
    // 先寻找绝对值最小的那个数，然后分别向两边移动
    vector<int> sortedSquares(vector<int>& nums)
    {
        int minInd = -1;
        // 寻找绝对值最小的那个数
        for (int i = 0; i < nums.size() - 1; ++i) {
            // 只有当前值严格小于后面的值的时候，当前值才是最小值
            // 当前值绝对值大于等于后面的时候，跳过
            if (abs(nums[i]) >= abs(nums[i + 1])) {
                continue;
            }
            // 由于数组是有序的，因此寻找到绝对值最小值就可以跳出循环
            minInd = i;
            break;
        }
        // 由于是i和i+1比，最小值是最后一个数的情况没办法覆盖
        // 因此当最小值是最后一个时，单独考虑
        if (minInd == -1) {
            minInd = nums.size() - 1;
        }
        vector<int> res;
        // 已经知道了最小值，先将其加入到数组中
        res.push_back(nums[minInd] * nums[minInd]);

        // 在最小索引的两边定义两个指针
        int left = minInd - 1;
        int right = minInd + 1;
        // left和right只要有一个合法的就可以
        while (left >= 0 || right < nums.size()) {
            // 对于不合法的情况，不求平方值
            int l2 = -1;
            if (left >= 0) {
                l2 = nums[left] * nums[left];
            }
            int r2 = -1;
            if (right < nums.size()) {
                r2 = nums[right] * nums[right];
            }

            // 分别考虑两个指针的合法情况以及平方大小
            if (l2 != -1 && r2 != -1) {
                if (l2 < r2) {
                    res.push_back(l2);
                    --left;
                } else {
                    res.push_back(r2);
                    ++right;
                }
            } else if (l2 == -1 && r2 != -1) {
                res.push_back(r2);
                ++right;
            } else if (l2 != -1 && r2 == -1) {
                res.push_back(l2);
                --left;
            } else {
                break;
            }
        }
        return res;
    }
};

```
