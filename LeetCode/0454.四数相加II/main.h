#include "Utils.hpp"
#include <unordered_map>

using namespace std;

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
