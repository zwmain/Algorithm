#include "Utils.hpp"
#include <string>
#include <vector>

using namespace std;

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
