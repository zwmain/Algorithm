# 0145.二叉树的后序遍历

链接：[0145.二叉树的后序遍历](https://leetcode.cn/problems/binary-tree-postorder-traversal/)

迭代法1：在前序的基础上，调换左右子树的添加顺序，得到中、右、左序列，最后在逆序，即可得到左、右、中的后序。

```c++
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> res;
        recursePost(root, res);
        return res;
    }
    void recursePost(TreeNode* node, vector<int>& res)
    {
        if (node == nullptr) {
            return;
        }
        recursePost(node->left, res);
        recursePost(node->right, res);
        res.push_back(node->val);
    }
    // 后续遍历，迭代版
    // 由前序代码改动得到
    vector<int> postorderTraversal2(TreeNode* root)
    {
        vector<int> res;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* cur = stk.top();
            stk.pop();
            if (cur == nullptr) {
                continue;
            }
            res.push_back(cur->val);
            // 和前序不同，先左子树入栈，这样结果就变为中、右、左
            // 最后将结果逆序，得到后序，左、右、中
            if (cur->left) {
                stk.push(cur->left);
            }
            if (cur->right) {
                stk.push(cur->right);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

```
