#include "Utils.hpp"
#include <queue>

using namespace std;

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
