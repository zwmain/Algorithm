#include "Utils.hpp"
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

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
