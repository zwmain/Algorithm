#include "Utils.hpp"
#include <queue>

using namespace std;

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
