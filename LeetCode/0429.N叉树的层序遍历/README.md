# 0429.N叉树的层序遍历

链接：[0429.N叉树的层序遍历](https://leetcode.cn/problems/n-ary-tree-level-order-traversal/)

在做这道题之前，需要理解**0102.二叉树的层序遍历**。

与二叉树层序遍历相比，本题只在子节点添加方式上有不同，二叉树是分左右子树，多叉树是遍历`children`数组，其他方面没有不同。

```c++
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root)
    {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }

        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            size_t curSize = q.size();
            vector<int> row;
            for (size_t i = 0; i < curSize; ++i) {
                Node* cur = q.front();
                q.pop();
                row.push_back(cur->val);
                for (Node* i : cur->children) {
                    if (i) {
                        q.push(i);
                    }
                }
            }
            res.push_back(row);
        }

        return res;
    }
};

```
