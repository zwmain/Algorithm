#pragma once
#include<iostream>
using namespace std;

class Solution {
public:
    int sqrt(int x)
    {
        // 需要考虑溢出
        if (x <= 0) return 0;
        int left = 1, right = x;
        while (left < right) {
            int middle = left + (right - left) / 2;
            // middle*middle<=x && (middle + 1)*(middle + 1)>x
            // 改用除法防止溢出
            if (middle <= x / middle && (middle + 1) > x / (middle + 1)) {
                return middle;
            }

            if (middle > x / middle) {
                right = middle;
            }
            else {
                left = middle;
            }
        }
        return left;
    }
};
