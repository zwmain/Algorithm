# 0860.柠檬水找零

链接：[0860.柠檬水找零](https://leetcode.cn/problems/lemonade-change/)

只有三种情况：

1. 5元，直接手下
2. 10元，找零5，同时10增加
3. 20元，找零15，优先10+5，其次5*3

```c++
class Solution {
public:
    bool lemonadeChange(vector<int>& bills)
    {
        // 只有三种情况
        // 分别记录三种面值的数量
        // 由于20面值只进不出，所以也可以不做记录
        int five = 0;
        int ten = 0;
        for (int b : bills) {
            if (b == 5) {
                // 直接收取
                ++five;
                continue;
            }
            if (b == 10) {
                if (five <= 0) {
                    // 没有5了
                    return false;
                }
                --five;
                ++ten;
                continue;
            }
            if (b == 20) {
                // 遇到20就要找15，优先10+5，其次5*3
                if (five > 0 && ten > 0) {
                    --five;
                    --ten;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

```

