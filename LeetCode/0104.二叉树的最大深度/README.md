# 0104.二叉树的最大深度

链接：[0104.二叉树的最大深度](https://leetcode.cn/problems/maximum-depth-of-binary-tree/)

在做这道题之前，需要理解**0102.二叉树的层序遍历**。

层序遍历本身就包含“一层一层”的概念，只要按层递加，最终结果就是整棵树的层数。

递归写法：通过自底向上求高度的方法求深度，对于根节点来说，其高度就是二叉树的最大深度。
递归求高度，当前节点需要直到两颗子树的高度，然后大的那个值+1就是当前节点的高度。
对于空节点来说，高度为0。

递归写法2：通过自顶向下直接求二叉树深度，当走到底时，刷新最大深度。相当于计算了所有深度，并且比较，得出最大深度。

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
    // 递归写法，自底向上求二叉树的高度，root的高度就是二叉树的深度
    int maxDepth2(TreeNode* root)
    {
        int res = getHeight(root);
        return res;
    }
    int getHeight(TreeNode* node)
    {
        // 节点为空时，高度为0
        if (node == nullptr) {
            return 0;
        }
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        // 当前节点高度就是左右子树高度大的那个+1
        int max = leftHeight > rightHeight ? leftHeight : rightHeight;
        return max + 1;
    }
    // 递归写法，直接求二叉树的深度
    int maxDepth3(TreeNode* root)
    {
        if (root == nullptr) {
            return 0;
        }
        getDepth(root, 1);
        return _maxDepth;
    }
    void getDepth(TreeNode* node, int depth)
    {
        if (node == nullptr) {
            depth -= 1;
            if (depth > _maxDepth) {
                _maxDepth = depth;
            }
            return;
        }
        getDepth(node->left, depth + 1);
        getDepth(node->right, depth + 1);
    }

private:
    int _maxDepth = 0;
};

```
