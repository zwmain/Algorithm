# 0226.翻转二叉树

链接：[0226.翻转二叉树](https://leetcode.cn/problems/invert-binary-tree/)

递归法：如果当前节点为空，返回空；反转左右节点；调换当前节点左右节点。可以前序也可以后序。这里采用后序。

迭代法：迭代法也由递归改迭代得到，由于前序迭代写法较为简单，这里迭代法使用前序。

```c++
class Solution {
public:
    TreeNode* invertTree(TreeNode* root)
    {
        if (root == nullptr) {
            return nullptr;
        }
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
    TreeNode* invertTree2(TreeNode* root)
    {
        if (root == nullptr) {
            return nullptr;
        }
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* cur = stk.top();
            stk.pop();
            swap(cur->left, cur->right);
            if (cur->left) {
                stk.push(cur->left);
            }
            if (cur->right) {
                stk.push(cur->right);
            }
        }
        return root;
    }
};

```
