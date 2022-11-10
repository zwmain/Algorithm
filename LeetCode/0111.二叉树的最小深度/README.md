# 0111.二叉树的最小深度

链接：[0111.二叉树的最小深度](https://leetcode.cn/problems/minimum-depth-of-binary-tree/)

在做这道题之前，需要理解**0102.二叉树的层序遍历**。

层序遍历是从上到下，从左到右，第一个遇到的左右子节点都为空的节点，其所在层数就是最小层数。

递归法：通过自底向上求高度的方法求最小深度，每次获取当前节点左右子树的高度，然后取高度小的值+1。
但是需要注意，一边子树有可能不存在，此时子树高度没有参考意义。如果左子树不存在，那就只取右子树高度+1；如果右子树不存在，那就只取左子树高度+1。
如果都不存在，那么和都存在一致，没有区别。

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
    int minDepth2(TreeNode* root)
    {
        int res = getHeight(root);
        return res;
    }
    int getHeight(TreeNode* node)
    {
        if (node == nullptr) {
            return 0;
        }
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);

        if (node->left == nullptr && node->right != nullptr) {
            // 如果左子树为空，右子树不为空，左子树不存在，返回右子树高度+1
            return rightHeight + 1;
        } else if (node->left != nullptr && node->right == nullptr) {
            // 如果左子树不为空，右子树为空，右子树不存在，返回左子树+1
            return leftHeight + 1;
        } else {
            // 如果左右子树都不存在或者都存在，取高度小的值+1
            int min = leftHeight < rightHeight ? leftHeight : rightHeight;
            return min + 1;
        }
    }
};

```
