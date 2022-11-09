#include "Utils.hpp"
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            size_t curSize = q.size();
            vector<int> row;
            for (size_t i = 0; i < curSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                row.push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            res.push_back(row);
        }
        // 和普通层序遍历相比，就多了一个逆序
        reverse(res.begin(), res.end());
        return res;
    }
};
