# 0104.二叉树的最大深度

链接：[0104.二叉树的最大深度](https://leetcode.cn/problems/maximum-depth-of-binary-tree/)

在做这道题之前，需要理解**0102.二叉树的层序遍历**。

层序遍历本身就包含“一层一层”的概念，只要按层递加，最终结果就是整棵树的层数。

```c++
class Solution {
public:
    int maxDepth(TreeNode* root)
    {
        if (root == nullptr) {
            return 0;
        }

        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        while (!q.empty()) {
            ++depth;
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
            }
        }

        return depth;
    }
};

```
