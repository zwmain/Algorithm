# 0257.二叉树的所有路径

[0257.二叉树的所有路径](https://leetcode.cn/problems/binary-tree-paths/)

思路：使用先序遍历，回溯法，进入递归的时候，将当前节点加入路径。
如果当前节点是叶子节点，那么输出，返回。
如果有左右子树，递归处理左右子树，因为进入递归会加入对应节点到路径，所以在离开递归时需要将节点移出路径。

```c++
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

```
