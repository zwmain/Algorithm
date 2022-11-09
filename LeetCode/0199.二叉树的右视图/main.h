#include "Utils.hpp"
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            size_t curSize = q.size();
            for (size_t i = 0; i < curSize; ++i) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
                // 只有当本层最后一个元素时，才加入结果数组
                if (i == curSize - 1) {
                    res.push_back(cur->val);
                }
            }
        }

        return res;
    }
};
