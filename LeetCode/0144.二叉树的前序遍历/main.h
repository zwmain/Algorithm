#include "Utils.hpp"
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> res;
        recursePre(root, res);
        return res;
    }
    void recursePre(TreeNode* node, vector<int>& res)
    {
        if (node == nullptr) {
            return;
        }
        res.push_back(node->val);
        recursePre(node->left, res);
        recursePre(node->right, res);
    }
};
