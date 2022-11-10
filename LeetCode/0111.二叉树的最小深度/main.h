#include "Utils.hpp"
#include <queue>

using namespace std;

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
