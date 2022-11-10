# Day15.二叉树深度递归求解、满二叉树节点统计

## 0104.二叉树的最大深度

链接：[0104.二叉树的最大深度](https://leetcode.cn/problems/maximum-depth-of-binary-tree/)

在做这道题之前，需要理解**0102.二叉树的层序遍历**。

层序遍历本身就包含“一层一层”的概念，只要按层递加，最终结果就是整棵树的层数。

递归写法：通过自底向上求高度的方法求深度，对于根节点来说，其高度就是二叉树的最大深度。
递归求高度，当前节点需要直到两颗子树的高度，然后大的那个值+1就是当前节点的高度。
对于空节点来说，高度为0。

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
};

```

## 0111.二叉树的最小深度

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

## 0222.完全二叉树的节点个数

链接：[0222.完全二叉树的节点个数](https://leetcode.cn/problems/count-complete-tree-nodes/)

因为是完全二叉树，如果整棵树不是满二叉树，那么局部子树也一定存在满二叉树，只要判断处满二叉树就可以利用公式，直接求出数量。

对于满二叉树来说，分别沿着左右两边一直走下去，深度是一致的。

如果以当前节点为根节点的子树不是满二叉树，那么就向普通树那样，分别求两颗子树，再相加。

```c++
class Solution {
public:
    int countNodes(TreeNode* root)
    {
        if (root == nullptr) {
            return 0;
        }
        int h = isFullTree(root);
        if (h > 0) {
            return pow(2, h) - 1;
        } else {
            // 如果不是满二叉树，分别求两个子树，再相加
            int lh = countNodes(root->left);
            int rh = countNodes(root->right);
            return lh + rh + 1;
        }
    }
    // 判断是否是满二叉树
    // 如果是返回深度，>=1
    // 如果不是返回0
    int isFullTree(TreeNode* node)
    {
        // 对于满二叉树来说
        // 沿着左右一路向下走，两边深度是一样的
        TreeNode* left = node->left;
        int lh = 1;
        while (left) {
            left = left->left;
            ++lh;
        }
        TreeNode* right = node->right;
        int rh = 1;
        while (right) {
            right = right->right;
            ++rh;
        }
        return lh == rh ? lh : 0;
    }
};

```


