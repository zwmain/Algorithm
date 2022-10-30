# Day06.哈希表

## 0242.有效的字母异位词

链接：[0242.有效的字母异位词](https://leetcode.cn/problems/valid-anagram/)

思路：由于只包含小写字母，可以借助计数判断元素是否重复。建立一个26大小的数组，对于第一个字符串，每个字符对应的计数加1；第二个字符串，每个字符减1。
如果最后数组中都是0，那么就说明两个字符串中的字符一致。

```c++
class Solution {
public:
    bool isAnagram(string s, string t)
    {
        vector<int> cntArr(26);
        for (size_t i = 0; i < cntArr.size(); ++i) {
            cntArr[i] = 0;
        }
        for (char c : s) {
            cntArr[c - 'a'] += 1;
        }
        for (char c : t) {
            cntArr[c - 'a'] -= 1;
        }
        for (size_t i = 0; i < 26; ++i) {
            if (cntArr[i] != 0) {
                return false;
            }
        }
        return true;
    }
};

```

## 0349.两个数组的交集

链接：[0349.两个数组的交集](https://leetcode.cn/problems/intersection-of-two-arrays/)

思路：借助集合，统计第一个数组中的数，然后遍历第二个数组，如果集合中有这个数，则添加到交集中，然后从集合中移除这个数，继续遍历。

```c++
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        set<int> repeat;
        for (int i : nums1) {
            repeat.insert(i);
        }
        vector<int> res;
        for (int i : nums2) {
            auto it = repeat.find(i);
            if (it != repeat.end()) {
                res.push_back(i);
                repeat.erase(it);
            }
        }
        return res;
    }
};

```

## 0202.快乐数

链接：[0202.快乐数](https://leetcode.cn/problems/happy-number/)

思路：这道题的重点是如何判断是否会陷入无限循环。只有当计算过程中，平方和重复出现才会无限循环。所以需要借助集合记录求解过程中的数。
如果没有重复就一直计算下去，如果重复就立即返回。

```c++
class Solution {
public:
    bool isHappy(int n)
    {
        unordered_set<int> numSet;
        int sum = 0;
        while (true) {
            sum = getSum(n);
            if (sum == 1) {
                return true;
            }
            auto it = numSet.find(sum);
            if (it == numSet.end()) {
                numSet.insert(sum);
                n = sum;
            } else {
                return false;
            }
        }
    }

    int getSum(int n)
    {
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
};

```

## 0001.两数之和

链接：[0001.两数之和](https://leetcode.cn/problems/two-sum/)

思路：借助map，记录当前值和索引。每次计算target和当前值的差，查找这个差，如果查找到，说明这个差已经存在于数组中。当前值和差所对应的索引就是答案。

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> numMap;
        for (int i = 0; i < nums.size(); ++i) {
            int val = target - nums[i];
            auto it = numMap.find(val);
            if (it != numMap.end()) {
                return { it->second, i };
            }
            numMap.insert({ nums[i], i });
        }
        return { -1, -1 };
    }
};

```

