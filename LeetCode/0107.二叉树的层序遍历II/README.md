# 0107.二叉树的层序遍历II

链接：[0107.二叉树的层序遍历II](https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/)

在做这道题之前，需要理解**0102.二叉树的层序遍历**。本题只是在普通层序遍历的基础上多了逆序。

```c++
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            size_t curSize = q.size();
            vector<int> row;
            for (size_t i = 0; i < curSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                row.push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            res.push_back(row);
        }
        // 和普通层序遍历相比，就多了一个逆序
        reverse(res.begin(), res.end());
        return res;
    }
};

```
