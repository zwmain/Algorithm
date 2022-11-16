# 0235.二叉搜索树的最近公共祖先

链接：[0235.二叉搜索树的最近公共祖先](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/)

二叉搜索树是有序的，如果p,q在当前节点两侧，即一个大于当前节点，一个小于当前节点，那么当前节点就是它们的公共祖先。

如果p,q都比当前值小，说明目标值在左子树，遍历左子树。

如果p,q都比当前值大，说明目标值在右子树，遍历右子树。

```c++
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

```
