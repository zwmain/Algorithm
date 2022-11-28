#include "Utils.hpp"
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    static bool cmp(int a, int b)
    {
        return abs(a) > abs(b);
    }

public:
    int largestSumAfterKNegations(vector<int>& nums, int k)
    {
        if (nums.empty()) {
            return 0;
        }
        // 把绝对值大的放到前面
        sort(nums.begin(), nums.end(), cmp);

        for (size_t i = 0; i < nums.size() && k > 0; ++i) {
            if (nums[i] < 0) {
                nums[i] = 0 - nums[i];
                --k;
            }
        }
        if (k > 0 && k % 2 == 1) {
            int v = nums.back();
            nums.back() = 0 - v;
        }
        int sum = 0;
        for (int i : nums) {
            sum += i;
        }
        return sum;
    }
};
