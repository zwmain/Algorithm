#include "Utils.hpp"

using namespace std;

#define INPUT_FILE "../input.txt"

class NumArray {
public:
    NumArray(vector<int>& nums)
        : _nums(nums)
    {
    }

    int sumRange(int left, int right)
    {
        int cnt = 0;
        for (int i = left; i <= right; ++i) {
            cnt += _nums[i];
        }
        return cnt;
    }

private:
    vector<int>& _nums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
