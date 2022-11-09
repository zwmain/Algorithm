# 0101.对称二叉树

链接：[0101.对称二叉树](https://leetcode.cn/problems/symmetric-tree/)

[0101.对称二叉树文字讲解](https://programmercarl.com/0101.%E5%AF%B9%E7%A7%B0%E4%BA%8C%E5%8F%89%E6%A0%91.html)

[0101.对称二叉树视频讲解](https://www.bilibili.com/video/BV1ue4y1Y7Mf/)

递归法：判断一个二叉树是否对称，需要判断两颗子树的两侧值是否相等。左子树的左侧和右子树的右侧（外侧），左子树的右侧和右子树的左侧（内侧）。
只有在确定两边子树是否对称的情况下，才能根据结果确定当前树是否对称，所以需要用后序遍历。
由于需要对两边子树的值进行判断，因此递归函数应该接收两个数节点。

迭代法1：一种思路是在分层迭代的基础上，获得一层元素，然后判断这一层是否对称，这种方法需要额外的与层宽度有关的空间。这里不用。

迭代法2：普通迭代，不需要分层，只不过一次处理两颗子树两边的节点。
对于节点的判断与递归法相似，都需要判断左子树的左侧和右子树的右侧（外侧），左子树的右侧和右子树的左侧（内侧）。

```c++
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
            return false;
        } else if (left != nullptr && right == nullptr) {
            return false;
        } else if (left == nullptr && right == nullptr) {
            return true;
        } else if (left->val != right->val) {
            return false;
        } else {
            // 外侧，左树的左侧和右树的右侧
            bool outside = compare(left->left, right->right);
            // 内侧，左树的右侧和右树的左侧
            bool inside = compare(left->right, right->left);
            // 在确定两棵子树是否是对称的之后，才能得到最终结果
            return outside && inside;
        }
    }
    // 迭代法
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

```
