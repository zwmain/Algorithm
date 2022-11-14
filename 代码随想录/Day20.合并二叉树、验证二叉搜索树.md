# Day20.合并二叉树、验证二叉搜索树

## 0654.最大二叉树

链接：[0654.最大二叉树](https://leetcode.cn/problems/maximum-binary-tree/)

思路：总体为前序遍历，先构造中间，再构造两边的子树，需要处理好数组区间问题。

```c++
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums)
    {
        if (nums.empty()) {
            return nullptr;
        }
        int ind = findMaxVal(nums);
        TreeNode* node = new TreeNode(nums[ind]);
        vector<int> leftNums(nums.begin(), nums.begin() + ind);
        node->left = constructMaximumBinaryTree(leftNums);
        vector<int> rightNums(nums.begin() + (ind + 1), nums.end());
        node->right = constructMaximumBinaryTree(rightNums);
        return node;
    }
    int findMaxVal(const vector<int>& nums)
    {
        int ind = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[ind]) {
                ind = i;
            }
        }
        return ind;
    }
};

```

## 0617.合并二叉树

链接：[0617.合并二叉树](https://leetcode.cn/problems/merge-two-binary-trees/)

思路：同时递归两个树，保证二者同步，都递归左子树或都递归右子树，这里在root1的基础上改造，而不是新建一棵树。

```c++
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2)
    {
        // 如果root1为空，直接返回root2
        // 这里已经包含了二者都为空的情况
        if (root1 == nullptr) {
            return root2;
        }
        if (root2 == nullptr) {
            return root1;
        }
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};

```

## 0700.二叉搜索树中的搜索

链接：[0700.二叉搜索树中的搜索](https://leetcode.cn/problems/search-in-a-binary-search-tree/)

递归：如果当前节点为空，返回空；如果当前节点值等于目标，返回当前节点；如果当前节点小于目标，递归进右子树；如果当前节点大于目标，递归进左子树。

迭代：循环当前节点，如果当前节点值等于目标，返回当前节点；如果当前节点小于目标，当前节点等于右子树；如果当前节点大于目标，当前节点等于左子树。
循环退出，说明节点为空，没找到。

```c++
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val)
    {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->val == val) {
            return root;
        } else if (root->val < val) {
            return searchBST(root->right, val);
        } else {
            return searchBST(root->left, val);
        }
    }
    TreeNode* searchBST2(TreeNode* root, int val)
    {
        while (root) {
            if (root->val == val) {
                return root;
            } else if (root->val < val) {
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return root;
    }
};

```

## 0098.验证二叉搜索树

链接：[0098.验证二叉搜索树](https://leetcode.cn/problems/validate-binary-search-tree/)

平衡二叉树特性：中序遍历的结果是有序的，只要确定中序结果单调，那么这个二叉树就是平衡二叉树。

判断是否单调，需要看前一个元素和后一个元素的大小，如果前一个元素大于等于当前元素，那么不单调。

初始`_pre`指针为空，当第一次走过中序时，`_pre`就是当前节点。

先看左子树，是否为平衡二叉树，再看右子树是否为平衡二叉树。

```c++
class Solution {
public:
    bool isValidBST(TreeNode* root)
    {
        if (root == nullptr) {
            return true;
        }
        bool isOk = isValidBST(root->left);
        if (!isOk) {
            return false;
        }
        if (_pre != nullptr && _pre->val > root->val) {
            return false;
        }
        _pre = root;
        isOk = isValidBST(_pre->right);
        return isOk;
    }

private:
    TreeNode* _pre = nullptr;
};

```

