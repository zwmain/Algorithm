# 0637.二叉树的层平均值

链接：[0637.二叉树的层平均值](https://leetcode.cn/problems/average-of-levels-in-binary-tree/)

在做这道题之前，需要理解**0102.二叉树的层序遍历**。

在上一道题的基础上，确定了每一层元素后，直接统计平均值就可以了。

```c++
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root)
    {
        vector<double> res;
        if (root == nullptr) {
            return res;
        }

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            size_t curSize = q.size();
            double sum = 0;
            for (size_t i = 0; i < curSize; ++i) {
                TreeNode* cur = q.front();
                q.pop();
                sum += cur->val;
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
            }
            res.push_back(sum / curSize);
        }

        return res;
    }
};

```
