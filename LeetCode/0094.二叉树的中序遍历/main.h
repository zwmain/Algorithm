#include "Utils.hpp"
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> res;
        recurseIn(root, res);
        return res;
    }
    void recurseIn(TreeNode* node, vector<int>& res)
    {
        if (node == nullptr) {
            return;
        }
        recurseIn(node->left, res);
        res.push_back(node->val);
        recurseIn(node->right, res);
    }
    // 中序遍历，迭代法
    vector<int> inorderTraversal2(TreeNode* root)
    {
        vector<int> res;
        stack<TreeNode*> stk;
        // 中序遍历，遍历的节点和访问的节点不同，需要借助辅助指针
        TreeNode* cur = root;
        while (cur != nullptr || !stk.empty()) {
            // 记录指针走过的节点
            if (cur != nullptr) {
                stk.push(cur);
                // 一直向左走
                cur = cur->left;
            } else {
                // cur为空说明子树走到底了
                cur = stk.top();
                stk.pop();
                // 访问栈顶，之前压入的中间节点
                res.push_back(cur->val);
                // 左子树走完了，中间也走了，检查右子树
                cur = cur->right;
            }
        }
        return res;
    }
};
