# 0145.二叉树的后序遍历

链接：[0145.二叉树的后序遍历](https://leetcode.cn/problems/binary-tree-postorder-traversal/)

迭代法1：在前序的基础上，调换左右子树的添加顺序，得到中、右、左序列，最后在逆序，即可得到左、右、中的后序。

法1是在前序的基础上得到的，而且还需要最终逆序，不太符合“遍历”的感觉。

迭代法2：后序遍历，遍历的节点和访问节点不相同，需要记录走过的节点。对于后序遍历，一个节点能否访问，必须看上一个访问的节点是不是右节点，只有检查右节点后，才能确定是否访问当前节点，因此还需要记录上一个访问的节点。

1. 如果当前节点不是空，入栈，向左走
2. 说明子树已经遍历结束，需要查看栈中已经走过的节点。
   1. 如果当前节点右节点为空，不存在右子树，直接访问，出栈，更新pre，cur设置为空，表示当前子树已经访问完毕。
   2. 如果当前节点右节点不为空，但右节点是上一个访问的节点，直接访问，出栈，更新pre，cur设置为空。
   3. 如果存在右节点，且右节点不是上一个访问的节点，`cur=cur->right`，进入右子树，回到开始。

```c++
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> res;
        recursePost(root, res);
        return res;
    }
    void recursePost(TreeNode* node, vector<int>& res)
    {
        if (node == nullptr) {
            return;
        }
        recursePost(node->left, res);
        recursePost(node->right, res);
        res.push_back(node->val);
    }
    // 后续遍历，迭代版
    // 由前序代码改动得到
    vector<int> postorderTraversal2(TreeNode* root)
    {
        vector<int> res;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* cur = stk.top();
            stk.pop();
            if (cur == nullptr) {
                continue;
            }
            res.push_back(cur->val);
            // 和前序不同，先左子树入栈，这样结果就变为中、右、左
            // 最后将结果逆序，得到后序，左、右、中
            if (cur->left) {
                stk.push(cur->left);
            }
            if (cur->right) {
                stk.push(cur->right);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
    // 后序遍历，迭代，不依赖前序
    vector<int> postorderTraversal2(TreeNode* root)
    {
        vector<int> res;
        stack<TreeNode*> stk;
        // 后序遍历，遍历的节点和访问节点不相同，需要记录走过的节点
        TreeNode* cur = root;
        // 对于后序遍历，一个节点能否访问，必须看上一个访问的节点是不是右节点
        // 只有检查右节点后，才能访问当前节点
        // 这里pre也可以为nullptr，不过要分清cur->right==nullptr和cur->right==pre两种情况，不能弄混
        TreeNode* pre = root;
        while (cur != nullptr || !stk.empty()) {
            if (cur != nullptr) {
                stk.push(cur);
                // 一直向左走
                cur = cur->left;
            } else {
                // 查看栈顶节点
                cur = stk.top();
                if (cur->right == nullptr) {
                    // 如果当前节点的右节点为空
                    // 可以访问当前节点
                    stk.pop();
                    res.push_back(cur->val);
                    // 更新pre
                    pre = cur;
                    // 当前子树已经走完了，继续出栈，所以cur为空
                    cur = nullptr;
                } else if (cur->right == pre) {
                    // 如果右节点不为空，但是为前一个访问的节点
                    // 可以访问当前节点
                    stk.pop();
                    res.push_back(cur->val);
                    // 更新pre
                    pre = cur;
                    // 当前子树已经走完了，继续出栈，所以cur为空
                    cur = nullptr;
                } else {
                    // 右节点不为空，也不是前一个访问的节点
                    // 进入右子树，回到循环开始
                    cur = cur->right;
                }
            }
        }
        return res;
    }
};

```
