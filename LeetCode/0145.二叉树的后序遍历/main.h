#include "Utils.hpp"
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> res;
        recursePost(root, res);
        return res;
    }
    void recursePost(TreeNode* node, vector<int>& res)
    {
        if (node == nullptr) {
            return;
        }
        recursePost(node->left, res);
        recursePost(node->right, res);
        res.push_back(node->val);
    }
};
