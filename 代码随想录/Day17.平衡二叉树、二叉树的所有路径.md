# Day17.平衡二叉树、二叉树的所有路径

## 0110.平衡二叉树

[0110.平衡二叉树](https://leetcode.cn/classic/problems/balanced-binary-tree/description/)

思路：分别获取左右子树的高度，然后判断左右子树的高度差是否大于1，
如果大于1，说明以当前节点为根节点的树，不是平衡二叉树，直接返回-1，尽快结束比较。
如果小于等于1，说明当前子树是平衡二叉树，返回子树高度大的值+1。

```c++
class Solution {
public:
    bool isBalanced(TreeNode* root)
    {
        int h = getHeight(root);
        return h != -1;
    }
    int getHeight(TreeNode* node)
    {
        // 如果当前节点为空，高度为0
        if (node == nullptr) {
            return 0;
        }
        // 获取左子树高度
        int lh = getHeight(node->left);
        // 如果左子树高度返回-1，说明左子树不是平衡二叉树
        // 直接返回，没有再继续遍历的必要了
        if (lh == -1) {
            return -1;
        }
        // 右子树与左子树同理
        int rh = getHeight(node->right);
        if (rh == -1) {
            return -1;
        }
        // 子树不是平衡二叉树
        if (abs(lh - rh) > 1) {
            return -1;
        }
        // 子树是平衡二叉树，返回高度值大的+1
        return max(lh, rh) + 1;
    }
};

```

## 0257.二叉树的所有路径

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

## 0404.左叶子之和

[0404.左叶子之和](https://leetcode.cn/problems/sum-of-left-leaves/)

思路：总体递归为后序，只有在知道左右子树的左叶子和后，再相加，当前子树的目标结果。
不过遍历寻找的是左叶子节点的父节点，这样才能确定要不要返回叶子节点的值。
如果当前节点是左叶子节点的父节点，那么左子树的左叶子和就是其值，**此处不能返回**。
如果不是左叶子的父节点，那么直接递归左子树。
右子树只需直接递归。

```c++
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root)
    {
        return getLeftSum(root);
    }
    int getLeftSum(TreeNode* node)
    {
        // 空节点，左叶子节点的和为0
        if (node == nullptr) {
            return 0;
        }
        if (node->left == nullptr && node->right == nullptr) {
            // 如果当前节点是叶子节点，但并不能确定是不是左叶子节点
            // 返回0
            return 0;
        }
        TreeNode* lc = node->left;
        int sumLeft = 0;
        if (lc != nullptr && lc->left == nullptr && lc->right == nullptr) {
            // 如果当前节点是左叶子节点的父节点
            // 那么左叶子节点的和就是左节点的值
            sumLeft = lc->val;
        } else {
            sumLeft = getLeftSum(node->left);
        }

        int sumRight = getLeftSum(node->right);

        return sumLeft + sumRight;
    }
};

```

