# 0513.找树左下角的值

[0513.找树左下角的值](https://leetcode.cn/problems/find-bottom-left-tree-value/)

左下角，首先要“最深”，即深度最大。然后在深度最大的情况下，最左。递归时，每递归一层，深度+1，可以确定深度值。
只要保证左子树在右子树前面递归，那么就可以保证“最左”

```c++
class Solution {
public:
    // 左下角，首先要“最深”，即深度最大
    // 然后在深度最大的情况下，最左
    // 递归时，每递归一层，深度+1，可以确定深度值
    // 只要保证左子树在右子树前面递归，那么就可以保证“最左”
    int findBottomLeftValue(TreeNode* root)
    {
        recurse(root, 1);
        return _blNode->val;
    }
    void recurse(TreeNode* node, int depth)
    {
        if (node == nullptr) {
            return;
        }
        // 如果当前节点是叶节点了
        if (node->left == nullptr && node->right == nullptr) {
            // 判断当前节点深度
            if (depth > _maxDepth) {
                // 如果深度大于最大深度，更新结果
                _blNode = node;
                _maxDepth = depth;
            }
            return;
        }
        if (node->left) {
            recurse(node->left, depth + 1);
        }
        if (node->right) {
            recurse(node->right, depth + 1);
        }
    }

private:
    int _maxDepth = INT_MIN;
    TreeNode* _blNode = nullptr;
};

```

# 0112.路径总和

[0112.路径总和](https://leetcode.cn/problems/path-sum/)

思路；递归函数设置一个计数，计数初始值为`target`。
每次递归前计数就减去待递归节点值，如果节点为叶节点且计数为0，返回`true`，终止递归。

```c++
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum)
    {
        if (root == nullptr) {
            return false;
        }
        return recurse(root, targetSum - root->val);
    }
    bool recurse(TreeNode* node, int cnt)
    {
        if (node == nullptr) {
            return cnt == 0;
        }
        if (node->left == nullptr && node->right == nullptr) {
            return cnt == 0;
        }
        if (node->left) {
            // 显式的写出回溯过程
            cnt -= node->left->val;
            bool k = recurse(node->left, cnt);
            cnt += node->left->val;
            if (k) {
                return true;
            }
        }
        if (node->right) {
            cnt -= node->right->val;
            bool k = recurse(node->right, cnt);
            cnt += node->right->val;
            if (k) {
                return true;
            }
        }
        return false;
    }
};

```

# 106. 从中序与后序遍历序列构造二叉树

[106. 从中序与后序遍历序列构造二叉树](https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)

思路：通过后序数组获取头结点，根据这个头结点在中序数组查找头结点的位置，头结点左面就是左子树，右面就是右子树。
根据左右子树长度，又可以在后序数组中确定左右子树。

```c++
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        if (inorder.empty() || postorder.empty()) {
            return nullptr;
        }
        return traversal(inorder, postorder);
    }

private:
    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder)
    {
        if (postorder.size() == 0)
            return NULL;

        // 后序遍历数组最后一个元素，就是当前的中间节点
        int rootValue = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(rootValue);

        // 叶子节点
        if (postorder.size() == 1)
            return root;

        // 找到中序遍历的切割点
        int delimiterIndex;
        for (delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++) {
            if (inorder[delimiterIndex] == rootValue)
                break;
        }

        // 切割中序数组
        // 左闭右开区间：[0, delimiterIndex)
        vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
        // [delimiterIndex + 1, end)
        vector<int> rightInorder(inorder.begin() + delimiterIndex + 1, inorder.end());

        // postorder 舍弃末尾元素
        postorder.resize(postorder.size() - 1);

        // 切割后序数组
        // 依然左闭右开，注意这里使用了左中序数组大小作为切割点
        // [0, leftInorder.size)
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        // [leftInorder.size(), end)
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());

        root->left = traversal(leftInorder, leftPostorder);
        root->right = traversal(rightInorder, rightPostorder);

        return root;
    }
};

```

