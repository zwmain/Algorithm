#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int left = 0;
        // 左闭右闭区间
        int right = nums.size() - 1;
        // 当左闭右闭区间时，左右是可以相等的
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int cur = nums[mid];
            if (cur == target) {
                return mid;
            } else if (cur > target) {
                // 当右边为闭合时，right需要mid-1
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }

    int search2(vector<int>& nums, int target)
    {
        int left = 0;
        // 左闭右开区间
        int right = nums.size();
        // 当左闭右开时，左右不能相等
        while (left < right) {
            int mid = left + (right - left) / 2;
            int cur = nums[mid];
            if (cur == target) {
                return mid;
            } else if (cur > target) {
                // 当左闭右开时，right值就是mid，不需要mid-1
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};
