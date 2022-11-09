# 0116.填充每个节点的下一个右侧节点指针

链接：[0116.填充每个节点的下一个右侧节点指针](https://leetcode.cn/problems/populating-next-right-pointers-in-each-node/)

在做这道题之前，需要理解**0102.二叉树的层序遍历**。

遍历到当前节点时，如果没到本层最后一个，就再取队列头部（不弹出），将当前的next指向该头部。

```c++
class Solution {
public:
    Node* connect(Node* root)
    {
        if (root == nullptr) {
            return root;
        }

        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            size_t curSize = q.size();
            for (size_t i = 0; i < curSize; ++i) {
                Node* cur = q.front();
                q.pop();
                if (i < curSize - 1) {
                    Node* next = q.front();
                    cur->next = next;
                }
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
            }
        }

        return root;
    }
};

```
