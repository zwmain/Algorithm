# 0102.二叉树的层序遍历

链接：[0102.二叉树的层序遍历](https://leetcode.cn/problems/binary-tree-level-order-traversal/)

迭代法：借助队列，每次进入循环的时候，记录当前队列大小，此时队列里的元素刚好为一层。
根据记录的大小，一次性访问这层的元素，同时把每个节点的子节点加入队列，构成“下一层”。

在了解这个方法之前，借助队列，不知道记录队列大小，以至于无法分层，而在循环开始处记录队列长度，正好是一层元素，可以分清楚每层。

递归法：递归整体逻辑由前序遍历改动得到，除了返回的数组外，还需要一个深度值。
深度值，代表层数，与res的下标一致，初始值为0。每当遍历到当前节点时，只需要`res[depth].push_back(cur->val)`即可。


```c++
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        // 借助队列实现层序遍历
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            // 记录队列在循环开始处的大小
            // 此时队列里的元素刚好为一层
            size_t curSize = q.size();
            vector<int> row;
            // 一次性遍历在同一层的元素
            for (size_t i = 0; i < curSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                row.push_back(node->val);
                // 将子节点加入队列，构成“下一层”
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            res.push_back(row);
        }
        return res;
    }
    vector<vector<int>> levelOrder2(TreeNode* root)
    {
        vector<vector<int>> res;
        size_t depth = 0;
        recurseFunc(root, res, 0);
        return res;
    }
    // 递归整体逻辑由前序遍历改动得到
    // 递归函数，除res数组外，还需要一个深度值
    // 深度值，代表层数，与res的下标一致，初始值为0
    void recurseFunc(TreeNode* cur, vector<vector<int>>& res, size_t depth)
    {
        if (cur == nullptr) {
            return;
        }
        if (depth == res.size()) {
            res.push_back(vector<int>());
        }
        res[depth].push_back(cur->val);

        recurseFunc(cur->left, res, depth + 1);
        recurseFunc(cur->right, res, depth + 1);
    }
};

```
