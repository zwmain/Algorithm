#include "Utils.hpp"
#include <cstdint>

using namespace std;

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
