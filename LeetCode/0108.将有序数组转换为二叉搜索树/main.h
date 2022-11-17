#include "Utils.hpp"

using namespace std;

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        if (nums.empty()) {
            return nullptr;
        }
        size_t mid = nums.size() / 2;
        TreeNode* cur = new TreeNode(nums[mid]);
        vector<int> left(nums.begin(), nums.begin() + mid);
        cur->left = sortedArrayToBST(left);
        vector<int> right(nums.begin() + (mid + 1), nums.end());
        cur->right = sortedArrayToBST(right);
        return cur;
    }
};
