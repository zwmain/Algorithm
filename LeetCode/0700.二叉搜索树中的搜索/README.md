# 0700.二叉搜索树中的搜索

链接：[0700.二叉搜索树中的搜索](https://leetcode.cn/problems/search-in-a-binary-search-tree/)

递归：如果当前节点为空，返回空；如果当前节点值等于目标，返回当前节点；如果当前节点小于目标，递归进右子树；如果当前节点大于目标，递归进左子树。

迭代：循环当前节点，如果当前节点值等于目标，返回当前节点；如果当前节点小于目标，当前节点等于右子树；如果当前节点大于目标，当前节点等于左子树。
循环退出，说明节点为空，没找到。

```c++
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val)
    {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->val == val) {
            return root;
        } else if (root->val < val) {
            return searchBST(root->right, val);
        } else {
            return searchBST(root->left, val);
        }
    }
    TreeNode* searchBST2(TreeNode* root, int val)
    {
        while (root) {
            if (root->val == val) {
                return root;
            } else if (root->val < val) {
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return root;
    }
};

```
