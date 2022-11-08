# 0144.二叉树的前序遍历

链接：[0144.二叉树的前序遍历](https://leetcode.cn/problems/binary-tree-preorder-traversal/)

非递归法：借助栈，由于前序遍历的遍历顺序和访问顺序是一致的，即遍历到的那个就是访问的那个节点，所以，先将根节点入栈，栈顶节点每次遍历的节点，直接访问。
如果节点为空，直接跳过。访问节点后，由于前序是中、左、右，所以先将右子树入栈，这样就可以保证左子树在右子树前面访问。

```c++
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> res;
        recursePre(root, res);
        return res;
    }
    void recursePre(TreeNode* node, vector<int>& res)
    {
        if (node == nullptr) {
            return;
        }
        res.push_back(node->val);
        recursePre(node->left, res);
        recursePre(node->right, res);
    }
    // 前序遍历，迭代法
    vector<int> preorderTraversal2(TreeNode* root)
    {
        vector<int> res;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            // 前序遍历，遍历的顺序和访问的顺序是一致的
            TreeNode* cur = stk.top();
            stk.pop();
            if (cur == nullptr) {
                continue;
            }
            res.push_back(cur->val);
            // 前序是中左右，所以右子树先入栈，这样右子树就会在左子树之后被访问
            if (cur->right) {
                stk.push(cur->right);
            }
            if (cur->left) {
                stk.push(cur->left);
            }
        }
        return res;
    }
};

```
