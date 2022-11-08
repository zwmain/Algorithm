#include "Utils.hpp"
#include <stack>

using namespace std;

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
    // 后序遍历，迭代版
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
    // 后序遍历，迭代，不依赖前序
    vector<int> postorderTraversal2(TreeNode* root)
    {
        vector<int> res;
        stack<TreeNode*> stk;
        // 后序遍历，遍历的节点和访问节点不相同，需要记录走过的节点
        TreeNode* cur = root;
        // 对于后序遍历，一个节点能否访问，必须看上一个访问的节点是不是右节点
        // 只有检查右节点后，才能访问当前节点
        // 这里pre也可以为nullptr，不过要分清cur->right==nullptr和cur->right==pre两种情况，不能弄混
        TreeNode* pre = root;
        while (cur != nullptr || !stk.empty()) {
            if (cur != nullptr) {
                stk.push(cur);
                // 一直向左走
                cur = cur->left;
            } else {
                // 查看栈顶节点
                cur = stk.top();
                if (cur->right == nullptr) {
                    // 如果当前节点的右节点为空
                    // 可以访问当前节点
                    stk.pop();
                    res.push_back(cur->val);
                    // 更新pre
                    pre = cur;
                    // 当前子树已经走完了，继续出栈，所以cur为空
                    cur = nullptr;
                } else if (cur->right == pre) {
                    // 如果右节点不为空，但是为前一个访问的节点
                    // 可以访问当前节点
                    stk.pop();
                    res.push_back(cur->val);
                    // 更新pre
                    pre = cur;
                    // 当前子树已经走完了，继续出栈，所以cur为空
                    cur = nullptr;
                } else {
                    // 右节点不为空，也不是前一个访问的节点
                    // 进入右子树，回到循环开始
                    cur = cur->right;
                }
            }
        }
        return res;
    }
};
