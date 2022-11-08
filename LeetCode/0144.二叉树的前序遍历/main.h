#include "Utils.hpp"
#include <stack>

using namespace std;

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
