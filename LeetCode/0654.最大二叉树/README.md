# 0654.最大二叉树

链接：[0654.最大二叉树](https://leetcode.cn/problems/maximum-binary-tree/)

思路：总体为前序遍历，先构造中间，再构造两边的子树，需要处理好数组区间问题。

```c++
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

```
