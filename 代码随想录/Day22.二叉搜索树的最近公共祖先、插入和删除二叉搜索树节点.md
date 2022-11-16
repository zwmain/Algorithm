# Day22.二叉搜索树的最近公共祖先、插入和删除二叉搜索树节点

## 0235.二叉搜索树的最近公共祖先

链接：[0235.二叉搜索树的最近公共祖先](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/)

二叉搜索树是有序的，如果p,q在当前节点两侧，即一个大于当前节点，一个小于当前节点，那么当前节点就是它们的公共祖先。

如果p,q都比当前值小，说明目标值在左子树，遍历左子树。

如果p,q都比当前值大，说明目标值在右子树，遍历右子树。

```cpp
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


## 0701.二叉搜索树中的插入操作

链接：[0701.二叉搜索树中的插入操作](https://leetcode.cn/problems/insert-into-a-binary-search-tree/)

这题不要想复杂了，就是普通插入，比当前值大，就去右子树；比当前值小就去左子树；等于当前值，就直接返回。

当找到空节点的时候，就是目标位置，返回新创建的节点。然后在递归进来的位置接收。

```cpp
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val)
    {
        if (root == nullptr) {
            TreeNode* node = new TreeNode(val);
            return node;
        }

        if (root->val > val) {
            root->left = insertIntoBST(root->left, val);
        } else if (root->val < val) {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};

```


## 0450.删除二叉搜索树中的节点

链接：[0450.删除二叉搜索树中的节点](https://leetcode.cn/problems/delete-node-in-a-bst/)

被删除节点的情况：

1. 目标不存在
2. 左为空，右为空，直接删除
3. 左不空，右为空，父节点直接指向左节点
4. 左为空，右不空，父节点直接指向右节点
5. 左不空，右不空，选择左右节点其中一个继位。这里选择右子树继位

右子树继位后，左子树应该挂在右子树上。由于右子树的所有值都大于左子树的值，所以左子树应该挂在右子树最左边的节点下。

```cpp
class Solution {
public:
    // 返回值是删除节点后，子树新的根节点
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        // 没找到删除的节点
        if (root == nullptr) {
            return nullptr;
        }

        if (root->val == key) {
            if (root->left == nullptr && root->right == nullptr) {
                // 左为空，右为空，直接删除
                delete root;
                // 递归前需要接收新节点
                return nullptr;
            } else if (root->left != nullptr && root->right == nullptr) {
                // 左不空，右为空，父节点直接指向左节点
                TreeNode* left = root->left;
                delete root;
                return left;
            } else if (root->left == nullptr && root->right != nullptr) {
                // 左为空，右不空，父节点直接指向右节点
                TreeNode* right = root->right;
                delete root;
                return right;
            } else {
                // 左不空，右不空，选择左右节点其中一个继位。这里选择右子树继位
                TreeNode* left = root->left;
                TreeNode* right = root->right;
                delete root;
                // 寻找右子树的最左侧，插入左子树
                TreeNode* ins = right;
                while (ins->left) {
                    ins = ins->left;
                }
                ins->left = left;
                return right;
            }
        } else if (root->val > key) {
            // 当前子树需要接收新子树根节点
            root->left = deleteNode(root->left, key);
        } else {
            root->right = deleteNode(root->right, key);
        }

        return root;
    }
};

```
