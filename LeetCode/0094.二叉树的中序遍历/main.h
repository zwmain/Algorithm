#include "Utils.hpp"
#include <queue>
#include <unordered_map>

using namespace std;

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
};
