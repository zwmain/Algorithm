#include "Utils.hpp"

using namespace std;

#define INPUT_FILE "../input.txt"

class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        size_t s = 0;
        size_t q = 0;
        while (s < nums.size()) {
            ++q;
            while (q < nums.size() && nums[s] == nums[q]) {
                nums.erase(nums.begin() + q);
            }
            s = q;
        }
        return nums.size();
    }
};
