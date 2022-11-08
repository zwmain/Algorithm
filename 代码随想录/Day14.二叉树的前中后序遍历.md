# Day14.二叉树的前中后序遍历

## 递归遍历模板

```c++
void recurse(TreeNode* node)
{
    if (node == nullptr) {
        return;
    }
    // 在这里访问节点就是前序
    recursePost(node->left, res);
    // 在这里访问节点就是中序
    recursePost(node->right, res);
    // 在这里访问节点就是后序
}

```

## 0144.二叉树的前序遍历

链接：[0144.二叉树的前序遍历](https://leetcode.cn/problems/binary-tree-preorder-traversal/)

非递归法：借助栈，由于前序遍历的遍历顺序和访问顺序是一致的，即遍历到的那个就是访问的那个节点，所以，先将根节点入栈，栈顶节点每次遍历的节点，直接访问。
如果节点为空，直接跳过。访问节点后，由于前序是中、左、右，所以先将右子树入栈，这样就可以保证左子树在右子树前面访问。

```c++
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> res;
        recursePre(root, res);
        return res;
    }
    void recursePre(TreeNode* node, vector<int>& res)
    {
        if (node == nullptr) {
            return;
        }
        res.push_back(node->val);
        recursePre(node->left, res);
        recursePre(node->right, res);
    }
    // 前序遍历，迭代法
    vector<int> preorderTraversal2(TreeNode* root)
    {
        vector<int> res;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            // 前序遍历，遍历的顺序和访问的顺序是一致的
            TreeNode* cur = stk.top();
            stk.pop();
            if (cur == nullptr) {
                continue;
            }
            res.push_back(cur->val);
            // 前序是中左右，所以右子树先入栈，这样右子树就会在左子树之后被访问
            if (cur->right) {
                stk.push(cur->right);
            }
            if (cur->left) {
                stk.push(cur->left);
            }
        }
        return res;
    }
};

```

## 0094.二叉树的中序遍历

链接：[0094.二叉树的中序遍历](https://leetcode.cn/problems/binary-tree-inorder-traversal/)

迭代法：中序遍历，遍历的节点和访问的节点不同，需要借助辅助指针，记录遍历走过的节点。

1. 如果当前指针不为空，直接入栈，然后向左走，继续循环，相当于一直向左走。
2. 如果当前指针为空，说明子树已经走到底了，访问栈顶元素，栈顶元素就是最后一个走过的，也应该是最先访问的。访问栈顶元素后，还需要向右走，进入右子树，回到1。

```c++
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> res;
        recurseIn(root, res);
        return res;
    }
    void recurseIn(TreeNode* node, vector<int>& res)
    {
        if (node == nullptr) {
            return;
        }
        recurseIn(node->left, res);
        res.push_back(node->val);
        recurseIn(node->right, res);
    }
    // 中序遍历，迭代法
    vector<int> inorderTraversal2(TreeNode* root)
    {
        vector<int> res;
        stack<TreeNode*> stk;
        // 中序遍历，遍历的节点和访问的节点不同，需要借助辅助指针
        TreeNode* cur = root;
        while (cur != nullptr || !stk.empty()) {
            // 记录指针走过的节点
            if (cur != nullptr) {
                stk.push(cur);
                // 一直向左走
                cur = cur->left;
            } else {
                // cur为空说明子树走到底了
                cur = stk.top();
                stk.pop();
                // 访问栈顶，之前压入的中间节点
                res.push_back(cur->val);
                // 左子树走完了，中间也走了，检查右子树
                cur = cur->right;
            }
        }
        return res;
    }
};

```

## 0145.二叉树的后序遍历

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

