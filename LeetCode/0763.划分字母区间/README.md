# 0763.划分字母区间

链接：[0763.划分字母区间](https://leetcode.cn/problems/partition-labels/)

统计每一个字符最后出现的位置

从头遍历字符，并更新字符的最远出现下标，如果找到字符最远出现位置下标和当前下标相等了，则找到了分割点

```c++
class Solution {
public:
    vector<int> partitionLabels(string s)
    {
        int hash[27] = { 0 }; // i为字符，hash[i]为字符出现的最后位置
        for (int i = 0; i < s.size(); i++) { // 统计每一个字符最后出现的位置
            hash[s[i] - 'a'] = i;
        }
        vector<int> result;
        int left = 0;
        int right = 0;
        for (int i = 0; i < s.size(); i++) {
            right = max(right, hash[s[i] - 'a']); // 找到字符出现的最远边界
            if (i == right) {
                result.push_back(right - left + 1);
                left = i + 1;
            }
        }
        return result;
    }
};

```



