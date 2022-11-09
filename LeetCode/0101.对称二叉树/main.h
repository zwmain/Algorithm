#include "Utils.hpp"
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    bool isSymmetric(TreeNode* root)
    {
        if (root == nullptr) {
            return true;
        }
        bool res = compare(root->left, root->right);
        return res;
    }
    // 判断是否对称，需要判断两颗树的两侧，需要同时遍历两个树
    bool compare(TreeNode* left, TreeNode* right)
    {
        if (left == nullptr && right != nullptr) {
            // 如果一个为空一个不为空，不对称
            return false;
        } else if (left != nullptr && right == nullptr) {
            // 如果一个为空一个不为空，不对称
            return false;
        } else if (left == nullptr && right == nullptr) {
            // 都为空，对称
            return true;
        } else if (left->val != right->val) {
            // 都不为空，但是值不相等，不对称
            return false;
        } else {
            // 都不为空，值相等，还得看两边子树是否对称
            // 外侧，左树的左侧和右树的右侧
            bool outside = compare(left->left, right->right);
            bool inside = compare(left->right, right->left);
            // 在确定两棵子树是否是对称的之后，才能得到最终结果
            return outside && inside;
        }
    }
    bool isSymmetric2(TreeNode* root)
    {
        if (root == nullptr) {
            return true;
        }
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty()) {
            TreeNode* left = q.front();
            q.pop();
            TreeNode* right = q.front();
            q.pop();
            if (left == nullptr && right != nullptr) {
                // 如果一个为空一个不为空，不对称
                return false;
            } else if (left != nullptr && right == nullptr) {
                // 如果一个为空一个不为空，不对称
                return false;
            } else if (left == nullptr && right == nullptr) {
                // 都为空，对称，继续判断其它节点
                continue;
            } else if (left->val != right->val) {
                // 都不为空，但是值不相等，不对称
                return false;
            } else {
                // 都不为空，值相等，还得看两边子树是否对称
                // 外侧，左树的左侧和右树的右侧
                q.push(left->left);
                q.push(right->right);
                // 内侧，左树的右侧和右树的左侧
                q.push(left->right);
                q.push(right->left);
            }
        }
        return true;
    }
};
