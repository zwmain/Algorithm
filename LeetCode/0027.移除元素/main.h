#include "Utils.hpp"

using namespace std;

#define INPUT_FILE "../input.txt"

class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        size_t ind = 0;
        while (ind < nums.size()) {
            while (ind < nums.size() && nums[ind] == val) {
                nums.erase(nums.begin() + ind);
            }
            ++ind;
        }
        return nums.size();
    }
};
