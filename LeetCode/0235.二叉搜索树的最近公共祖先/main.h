#include "Utils.hpp"

using namespace std;

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == nullptr) {
            return nullptr;
        }

        if (root->val > p->val && root->val > q->val) {
            // 如果p,q都比当前值小，说明目标值在左子树，遍历左子树
            return lowestCommonAncestor(root->left, p, q);
        } else if (root->val < p->val && root->val < q->val) {
            // 如果p,q都比当前值大，说明目标值在右子树，遍历右子树
            return lowestCommonAncestor(root->right, p, q);
        } else {
            // 当前值在p,q中间，那么就是最近公共祖先
            return root;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        while (root) {
            if (root->val > p->val && root->val > q->val) {
                // 如果p,q都比当前值小，说明目标值在左子树，遍历左子树
                root = root->left;
            } else if (root->val < p->val && root->val < q->val) {
                // 如果p,q都比当前值大，说明目标值在右子树，遍历右子树
                root = root->right;
            } else {
                // 当前值在p,q中间，那么就是最近公共祖先
                return root;
            }
        }
        return root;
    }
};
