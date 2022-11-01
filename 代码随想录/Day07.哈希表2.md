# 哈希表02

## 0454.四数相加II

链接：[0454.四数相加II](https://leetcode.cn/problems/4sum-ii/)

思路：这题需要的结果是元组的个数。将四个数组分为两组，先求前两个数组的和，构建一个map，key是“和”，value是“和”出现的次数。
然后在求解后两个数组，并算出与0的差。从map中查询这个“差”，如果查得到，那么计数加上出现的次数，注意不是加1。

```c++
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
    {
        // key是1、2两个数组元素的和
        // value是“和”出现的次数
        unordered_map<int, int> mapAB;
        for (auto i1 : nums1) {
            for (auto i2 : nums2) {
                int sum = i1 + i2;
                auto it = mapAB.find(sum);
                if (it == mapAB.end()) {
                    mapAB[sum] = 1;
                } else {
                    mapAB[sum] += 1;
                }
            }
        }

        int cnt = 0;
        // 遍历后两个数组
        for (auto i3 : nums3) {
            for (auto i4 : nums4) {
                // 求解后两个数组的元素和
                // 求解0与元素和的差
                int x = 0 - (i3 + i4);
                // 查找差是否在map中
                auto it = mapAB.find(x);
                if (it != mapAB.end()) {
                    cnt += it->second;
                }
            }
        }
        return cnt;
    }
};

```

## 0383.赎金信

链接：[0383.赎金信](https://leetcode.cn/problems/ransom-note/)

思路1：

使用map统计magzine各个字符的数量

遍历ransomNote字符串，从map中查询每个字符串，如果查询不到，则返回false

如果查询到了，则将统计数目-1，减到0的时候，移除该字符

```c++
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        map<char, int> mag_map;
        for (auto c : magazine) {
            auto it = mag_map.find(c);
            if (it == mag_map.end()) {
                mag_map.emplace(c, 1);
            } else {
                it->second += 1;
            }
        }
        for (auto c : ransomNote) {
            auto it = mag_map.find(c);
            if (it == mag_map.end()) {
                return false;
            } else {
                it->second -= 1;
                if (it->second == 0) {
                    mag_map.erase(it);
                }
            }
        }
        return true;
    }
};

```

思路2：

依然使用统计字符数目的方法，但是不用map，而是直接用数组

因为只有26个小写英文字母，数组就可以满足需求，完全没必要使用map

```c++
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        vector<int> arr(26);
        for (auto& c : magazine) {
            arr[c - 'a']++;
        }
        for (auto& c : ransomNote) {
            arr[c - 'a']--;
            if (arr[c - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};

```

## 0015.三数之和

链接：[0015.三数之和](https://leetcode.cn/problems/3sum/)

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

## 0454.四数相加II

链接：[0454.四数相加II](https://leetcode.cn/problems/4sum-ii/)

思路：这题需要的结果是元组的个数。将四个数组分为两组，先求前两个数组的和，构建一个map，key是“和”，value是“和”出现的次数。
然后在求解后两个数组，并算出与0的差。从map中查询这个“差”，如果查得到，那么计数加上出现的次数，注意不是加1。

```c++
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
    {
        // key是1、2两个数组元素的和
        // value是“和”出现的次数
        unordered_map<int, int> mapAB;
        for (auto i1 : nums1) {
            for (auto i2 : nums2) {
                int sum = i1 + i2;
                auto it = mapAB.find(sum);
                if (it == mapAB.end()) {
                    mapAB[sum] = 1;
                } else {
                    mapAB[sum] += 1;
                }
            }
        }

        int cnt = 0;
        // 遍历后两个数组
        for (auto i3 : nums3) {
            for (auto i4 : nums4) {
                // 求解后两个数组的元素和
                // 求解0与元素和的差
                int x = 0 - (i3 + i4);
                // 查找差是否在map中
                auto it = mapAB.find(x);
                if (it != mapAB.end()) {
                    cnt += it->second;
                }
            }
        }
        return cnt;
    }
};

```

