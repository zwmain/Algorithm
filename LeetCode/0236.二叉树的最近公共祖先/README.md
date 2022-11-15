# 0236.二叉树的最近公共祖先

链接：[0236.二叉树的最近公共祖先](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/)

后序遍历可以自底向上遍历二叉树，这样中节点就可以根据左右的结果判断。

查找时要考虑p,q本身就是公共节点的情况，直接返回其本身就可以。

1. 如果左右子树分别由p,q那么当前root就是公共祖先
2. 如果左为空，右不为空，说明p,q都在右子树里，公共祖先只在右子树里
3. 如果左不为空，右为空，说明p,q都在左子树里，公共祖先只在左子树里
4. 左右子树都没有

```c++
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == nullptr) {
            return nullptr;
        }
        // 如果子树根节点本身就是p,q的一个，那么将其直接返回
        if (root == p || root == q) {
            return root;
        }
        // 去左子树里寻找p或q
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        // 去右子树里寻找p或q
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left != nullptr && right != nullptr) {
            // 如果左右子树分别由p,q那么当前root就是公共祖先
            return root;
        } else if (left == nullptr && right != nullptr) {
            // 如果左为空，右不为空，说明p,q都在右子树里，公共祖先只在右子树里
            return right;
        } else if (left != nullptr && right == nullptr) {
            // 如果左不为空，右为空，说明p,q都在左子树里，公共祖先只在左子树里
            return left;
        } else {
            // 左右子树都没有
            return nullptr;
        }
    }
};

```

