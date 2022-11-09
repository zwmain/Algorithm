# 0199.二叉树的右视图

链接：[0199.二叉树的右视图](https://leetcode.cn/problems/binary-tree-right-side-view/)

在做这道题之前，需要理解**0102.二叉树的层序遍历**。

由于可以确定每层的元素，那么只要在每层的最后一个数加入结果数组就行。

```c++
class Solution {
public:
    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            size_t curSize = q.size();
            for (size_t i = 0; i < curSize; ++i) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
                // 只有当本层最后一个元素时，才加入结果数组
                if (i == curSize - 1) {
                    res.push_back(cur->val);
                }
            }
        }

        return res;
    }
};

```
