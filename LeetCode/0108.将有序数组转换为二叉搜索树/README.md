# 0108.将有序数组转换为二叉搜索树

链接：[0108.将有序数组转换为二叉搜索树](https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/)

为保证二叉搜索数高度平衡，每次需要取数组的中间节点作为根节点。然后前半部分数组为左子树。后半部分数组为右子树。

```c++
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

```
