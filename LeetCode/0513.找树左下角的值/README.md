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
