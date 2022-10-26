#include "Utils.hpp"

using namespace std;

class Solution {
public:
    // 移除元素第一版，借助了erase接口
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
    // 移除元素第二版，暴力解法
    int removeElement2(vector<int>& nums, int val)
    {
        if (nums.empty()) {
            return 0;
        }
        size_t length = nums.size();
        size_t ind = 0;
        // length随着元素移除会不断变小，当为0时退出
        while (length > 0 && ind < length) {
            if (nums[ind] == val) {
                // 当前值与目标值相等时，将后面的元素前移，覆盖当前值，这种方法可以保证元素顺序
                // 如果不考虑元素顺序，可以直接将最后一个元素放置在此处
                for (size_t i = ind + 1; i < length; ++i) {
                    nums[i - 1] = nums[i];
                }
                --length;
            } else {
                ++ind;
            }
        }
        return length;
    }
    // 双指针
    // 删除元素的基本思想是：将目标元素后面的元素前移，将快指针指向新数组中的元素
    // 慢指针指向旧数组中应该被替换的位置
    int removeElement2(vector<int>& nums, int val)
    {
        size_t slow = 0; // 指向需要被替换的位置
        size_t fast = 0; // 指向需要保留的位置
        for (fast; fast < nums.size(); ++fast) {
            // 只有当fast位置不等于目标值时，才会替换前面的位置
            // 当fast位置等于目标值时，跳过，slow位置没有被替换，因此不后移
            if (nums[fast] != val) {
                // 只有当fast不等于目标值时才会发生替换，++slow
                nums[slow] = nums[fast];
                ++slow;
            }
            // 不管是不是等于目标值，fast会一直后移
        }
        return slow;
    }
};
