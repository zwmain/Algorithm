# 0515.在每个树行中找最大值

链接：[0515.在每个树行中找最大值](https://leetcode.cn/problems/find-largest-value-in-each-tree-row/)

在做这道题之前，需要理解**0102.二叉树的层序遍历**。

在知道了每一层的元素情况下，遍历该层元素，寻找最小值。

```c++
class Solution {
public:
    vector<int> largestValues(TreeNode* root)
    {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            size_t curSize = q.size();
            TreeNode* cur = q.front();
            q.pop();
            int maxVal = cur->val;
            if (cur->left) {
                q.push(cur->left);
            }
            if (cur->right) {
                q.push(cur->right);
            }
            for (size_t i = 1; i < curSize; ++i) {
                cur = q.front();
                q.pop();
                if (cur->val > maxVal) {
                    maxVal = cur->val;
                }
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
            }
            res.push_back(maxVal);
        }

        return res;
    }
};

```
