# 0111.二叉树的最小深度

链接：[0111.二叉树的最小深度](https://leetcode.cn/problems/minimum-depth-of-binary-tree/)

在做这道题之前，需要理解**0102.二叉树的层序遍历**。

层序遍历是从上到下，从左到右，第一个遇到的左右子节点都为空的节点，其所在层数就是最小层数。

```c++
class Solution {
public:
    int minDepth(TreeNode* root)
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
                if (cur->left == nullptr && cur->right == nullptr) {
                    return depth;
                }
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
