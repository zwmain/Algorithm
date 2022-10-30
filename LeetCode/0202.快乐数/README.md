# 0202.快乐数

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
