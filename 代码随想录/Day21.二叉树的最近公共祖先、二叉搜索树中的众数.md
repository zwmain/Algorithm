# Day21.二叉树的最近公共祖先、二叉搜索树中的众数

## 0530.二叉搜索树的最小绝对差

链接：[0530.二叉搜索树的最小绝对差](https://leetcode.cn/problems/minimum-absolute-difference-in-bst/)

二叉搜索树，在中序遍历下是一个有序数组。那么最小绝对差一定从相邻两个数的绝对差中产生。

中序遍历二叉树，维护一个`pre`指针，指向前一个元素，每次更新绝对差。

```c++
class Solution {
public:
    int getMinimumDifference(TreeNode* root)
    {
        midRecurse(root);
        return _minVal;
    }

private:
    void midRecurse(TreeNode* node)
    {
        if (node == nullptr) {
            return;
        }
        midRecurse(node->left);
        if (_pre != nullptr) {
            int n = abs(node->val - _pre->val);
            if (n < _minVal) {
                _minVal = n;
            }
        }
        _pre = node;
        midRecurse(node->right);
    }

    TreeNode* _pre = nullptr;
    int _minVal = INT_MAX;
};

```



## 0501.二叉搜索树中的众数

链接：[0501.二叉搜索树中的众数](https://leetcode.cn/problems/find-mode-in-binary-search-tree/)

二叉搜索树中序遍历是一个有序数组，那么相等的数一定连续。

维护`pre`指针，当前值计数，最大计数。

如果`pre`为空，那么计数为1；如果`pre`与`cur`相等，那么计数+1；如果`pre`与`cur`不等，计数重新设置为1。

更新完计数后，更新`pre`指针。

根据计数，更新最大计数和结果数组。如果大于最大计数，那么更新最大计数，原结果集清空，加入当前值；如果等于计数，直接加入当前值。

```c++
class Solution {
public:
    vector<int> findMode(TreeNode* root)
    {
        _cnt = 0;
        _maxCnt = 0;
        _pre = nullptr;
        _res.clear();
        midRecurse(root);
        return _res;
    }

private:
    void midRecurse(TreeNode* node)
    {
        if (node == nullptr) {
            return;
        }
        midRecurse(node->left);
        if (_pre == nullptr) {
            _cnt = 1;
        } else if (_pre->val == node->val) {
            ++_cnt;
        } else {
            _cnt = 1;
        }
        _pre = node;
        if (_cnt > _maxCnt) {
            _maxCnt = _cnt;
            _res.clear();
            _res.push_back(_pre->val);
        } else if (_cnt == _maxCnt) {
            _res.push_back(_pre->val);
        }
        midRecurse(node->right);
    }

    int _cnt = 0;
    int _maxCnt = 0;
    vector<int> _res;
    TreeNode* _pre = nullptr;
};

```


## 0236.二叉树的最近公共祖先

链接：[0236.二叉树的最近公共祖先](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/)

后序遍历可以自底向上遍历二叉树，这样中节点就可以根据左右的结果判断。

查找时要考虑p,q本身就是公共节点的情况，直接返回其本身就可以。

1. 如果左右子树分别由p,q那么当前root就是公共祖先
2. 如果左为空，右不为空，说明p,q都在右子树里，公共祖先只在右子树里
3. 如果左不为空，右为空，说明p,q都在左子树里，公共祖先只在左子树里
4. 左右子树都没有

```c++
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == nullptr) {
            return nullptr;
        }
        // 如果子树根节点本身就是p,q的一个，那么将其直接返回
        if (root == p || root == q) {
            return root;
        }
        // 去左子树里寻找p或q
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        // 去右子树里寻找p或q
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left != nullptr && right != nullptr) {
            // 如果左右子树分别由p,q那么当前root就是公共祖先
            return root;
        } else if (left == nullptr && right != nullptr) {
            // 如果左为空，右不为空，说明p,q都在右子树里，公共祖先只在右子树里
            return right;
        } else if (left != nullptr && right == nullptr) {
            // 如果左不为空，右为空，说明p,q都在左子树里，公共祖先只在左子树里
            return left;
        } else {
            // 左右子树都没有
            return nullptr;
        }
    }
};

```

