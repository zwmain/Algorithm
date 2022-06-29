#include "Utils.hpp"

using namespace std;

#define INPUT_FILE "../input.txt"

class NumArray {
public:
    NumArray(vector<int>& nums)
        : _nums(nums)
    {
        _pre.resize(_nums.size() + 1);
        _pre[0] = 0;
        for (size_t i = 1; i < _pre.size(); ++i) {
            _pre[i] = _pre[i - 1] + _nums[i - 1];
        }
    }

    int sumRange(int left, int right)
    {
        // int cnt = 0;
        // for (int i = left; i <= right; ++i) {
        //     cnt += _nums[i];
        // }
        // return cnt;
        return _pre[right + 1] - _pre[left];
    }

private:
    vector<int>& _nums;
    vector<int> _pre;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
