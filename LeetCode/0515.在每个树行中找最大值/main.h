#include "Utils.hpp"
#include <queue>

using namespace std;

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
