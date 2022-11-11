#include "Utils.hpp"
#include <queue>

using namespace std;

class Solution {
public:
    bool isBalanced(TreeNode* root)
    {
        int h = getHeight(root);
        return h != -1;
    }
    int getHeight(TreeNode* node)
    {
        if (node == nullptr) {
            return 0;
        }
        int lh = getHeight(node->left);
        if (lh == -1) {
            return -1;
        }
        int rh = getHeight(node->right);
        if (rh == -1) {
            return -1;
        }
        if (abs(lh - rh) > 1) {
            return -1;
        }
        return max(lh, rh) + 1;
    }
};

