#include "Utils.hpp"

using namespace std;

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums)
    {
        if (nums.empty()) {
            return nullptr;
        }
        int ind = findMaxVal(nums);
        TreeNode* node = new TreeNode(nums[ind]);
        vector<int> leftNums(nums.begin(), nums.begin() + ind);
        node->left = constructMaximumBinaryTree(leftNums);
        vector<int> rightNums(nums.begin() + (ind + 1), nums.end());
        node->right = constructMaximumBinaryTree(rightNums);
        return node;
    }
    int findMaxVal(const vector<int>& nums)
    {
        int ind = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[ind]) {
                ind = i;
            }
        }
        return ind;
    }
};
