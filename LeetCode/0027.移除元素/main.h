#include "Utils.hpp"

using namespace std;

class Solution {
public:
    int removeElement0(vector<int>& nums, int val)
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
    int removeElement(vector<int>& nums, int val)
    {
        return 0;
    }
};
