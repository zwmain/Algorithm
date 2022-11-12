#include "Utils.hpp"

using namespace std;

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root)
    {
        vector<int> onePath;
        vector<string> res;
        getPath(root, onePath, res);
        return res;
    }
    void getPath(TreeNode* node, vector<int>& onePath, vector<string>& res)
    {
        // node为空，无效节点
        if (node == nullptr) {
            return;
        }
        // 先将当前节点加入路径
        onePath.push_back(node->val);
        // 如果是叶子节点，一个路径已经完毕，可以输出
        if (node->left == nullptr && node->right == nullptr) {
            res.push_back(pathToString(onePath));
            return;
        }

        if (node->left) {
            // 遍历左子树
            getPath(node->left, onePath, res);
            // 由于节点是在递归内部加入的，所以退出递归的时候，要回溯
            onePath.pop_back();
        }
        if (node->right) {
            getPath(node->right, onePath, res);
            onePath.pop_back();
        }
    }
    string pathToString(const vector<int>& path)
    {
        if (path.empty()) {
            return string();
        }
        string res = to_string(path[0]);
        for (size_t i = 1; i < path.size(); ++i) {
            res += "->";
            res += to_string(path[i]);
        }
        return res;
    }
};
