# Day15.二叉树层序遍历、对称二叉树

## 0102.二叉树的层序遍历

链接：[0102.二叉树的层序遍历](https://leetcode.cn/problems/binary-tree-level-order-traversal/)

迭代法：借助队列，每次进入循环的时候，记录当前队列大小，此时队列里的元素刚好为一层。
根据记录的大小，一次性访问这层的元素，同时把每个节点的子节点加入队列，构成“下一层”。

在了解这个方法之前，借助队列，不知道记录队列大小，以至于无法分层，而在循环开始处记录队列长度，正好是一层元素，可以分清楚每层。

递归法：递归整体逻辑由前序遍历改动得到，除了返回的数组外，还需要一个深度值。
深度值，代表层数，与res的下标一致，初始值为0。每当遍历到当前节点时，只需要`res[depth].push_back(cur->val)`即可。


```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        // 借助队列实现层序遍历
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            // 记录队列在循环开始处的大小
            // 此时队列里的元素刚好为一层
            size_t curSize = q.size();
            vector<int> row;
            // 一次性遍历在同一层的元素
            for (size_t i = 0; i < curSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                row.push_back(node->val);
                // 将子节点加入队列，构成“下一层”
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            res.push_back(row);
        }
        return res;
    }
    vector<vector<int>> levelOrder2(TreeNode* root)
    {
        vector<vector<int>> res;
        size_t depth = 0;
        recurseFunc(root, res, 0);
        return res;
    }
    // 递归整体逻辑由前序遍历改动得到
    // 递归函数，除res数组外，还需要一个深度值
    // 深度值，代表层数，与res的下标一致，初始值为0
    void recurseFunc(TreeNode* cur, vector<vector<int>>& res, size_t depth)
    {
        if (cur == nullptr) {
            return;
        }
        if (depth == res.size()) {
            res.push_back(vector<int>());
        }
        res[depth].push_back(cur->val);

        recurseFunc(cur->left, res, depth + 1);
        recurseFunc(cur->right, res, depth + 1);
    }
};

```


## 0107.二叉树的层序遍历II

链接：[0107.二叉树的层序遍历II](https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/)

在做这道题之前，需要理解**0102.二叉树的层序遍历**。本题只是在普通层序遍历的基础上多了逆序。

```cpp
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            size_t curSize = q.size();
            vector<int> row;
            for (size_t i = 0; i < curSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                row.push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            res.push_back(row);
        }
        // 和普通层序遍历相比，就多了一个逆序
        reverse(res.begin(), res.end());
        return res;
    }
};

```


## 0199.二叉树的右视图

链接：[0199.二叉树的右视图](https://leetcode.cn/problems/binary-tree-right-side-view/)

在做这道题之前，需要理解**0102.二叉树的层序遍历**。

由于可以确定每层的元素，那么只要在每层的最后一个数加入结果数组就行。

```cpp
class Solution {
public:
    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            size_t curSize = q.size();
            for (size_t i = 0; i < curSize; ++i) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
                // 只有当本层最后一个元素时，才加入结果数组
                if (i == curSize - 1) {
                    res.push_back(cur->val);
                }
            }
        }

        return res;
    }
};

```


## 0637.二叉树的层平均值

链接：[0637.二叉树的层平均值](https://leetcode.cn/problems/average-of-levels-in-binary-tree/)

在做这道题之前，需要理解**0102.二叉树的层序遍历**。

在上一道题的基础上，确定了每一层元素后，直接统计平均值就可以了。

```cpp
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

```


## 0429.N叉树的层序遍历

链接：[0429.N叉树的层序遍历](https://leetcode.cn/problems/n-ary-tree-level-order-traversal/)

在做这道题之前，需要理解**0102.二叉树的层序遍历**。

与二叉树层序遍历相比，本题只在子节点添加方式上有不同，二叉树是分左右子树，多叉树是遍历`children`数组，其他方面没有不同。

```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root)
    {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }

        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            size_t curSize = q.size();
            vector<int> row;
            for (size_t i = 0; i < curSize; ++i) {
                Node* cur = q.front();
                q.pop();
                row.push_back(cur->val);
                for (Node* i : cur->children) {
                    if (i) {
                        q.push(i);
                    }
                }
            }
            res.push_back(row);
        }

        return res;
    }
};

```


## 0515.在每个树行中找最大值

链接：[0515.在每个树行中找最大值](https://leetcode.cn/problems/find-largest-value-in-each-tree-row/)

在做这道题之前，需要理解**0102.二叉树的层序遍历**。

在知道了每一层的元素情况下，遍历该层元素，寻找最小值。

```cpp
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

```


## 0116.填充每个节点的下一个右侧节点指针

链接：[0116.填充每个节点的下一个右侧节点指针](https://leetcode.cn/problems/populating-next-right-pointers-in-each-node/)

在做这道题之前，需要理解**0102.二叉树的层序遍历**。

遍历到当前节点时，如果没到本层最后一个，就再取队列头部（不弹出），将当前的next指向该头部。

```cpp
class Solution {
public:
    Node* connect(Node* root)
    {
        if (root == nullptr) {
            return root;
        }

        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            size_t curSize = q.size();
            for (size_t i = 0; i < curSize; ++i) {
                Node* cur = q.front();
                q.pop();
                if (i < curSize - 1) {
                    Node* next = q.front();
                    cur->next = next;
                }
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
            }
        }

        return root;
    }
};

```


## 0117.填充每个节点的下一个右侧节点指针II

链接：[0117.填充每个节点的下一个右侧节点指针II](https://leetcode.cn/problems/populating-next-right-pointers-in-each-node-ii/)

在做这道题之前，需要理解**0102.二叉树的层序遍历**。

和**0116.填充每个节点的下一个右侧节点指针**没有任何区别。

遍历到当前节点时，如果没到本层最后一个，就再取队列头部（不弹出），将当前的next指向该头部。

```cpp
class Solution {
public:
    Node* connect(Node* root)
    {
        if (root == nullptr) {
            return root;
        }

        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            size_t curSize = q.size();
            for (size_t i = 0; i < curSize; ++i) {
                Node* cur = q.front();
                q.pop();
                if (i < curSize - 1) {
                    Node* next = q.front();
                    cur->next = next;
                }
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
            }
        }

        return root;
    }
};

```


## 0104.二叉树的最大深度

链接：[0104.二叉树的最大深度](https://leetcode.cn/problems/maximum-depth-of-binary-tree/)

在做这道题之前，需要理解**0102.二叉树的层序遍历**。

层序遍历本身就包含“一层一层”的概念，只要按层递加，最终结果就是整棵树的层数。

```cpp
class Solution {
public:
    int maxDepth(TreeNode* root)
    {
        if (root == nullptr) {
            return 0;
        }

        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        while (!q.empty()) {
            ++depth;
            size_t curSize = q.size();
            for (size_t i = 0; i < curSize; ++i) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
            }
        }

        return depth;
    }
};

```


## 0111.二叉树的最小深度

链接：[0111.二叉树的最小深度](https://leetcode.cn/problems/minimum-depth-of-binary-tree/)

在做这道题之前，需要理解**0102.二叉树的层序遍历**。

层序遍历是从上到下，从左到右，第一个遇到的左右子节点都为空的节点，其所在层数就是最小层数。

```cpp
class Solution {
public:
    int minDepth(TreeNode* root)
    {
        if (root == nullptr) {
            return 0;
        }

        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        while (!q.empty()) {
            ++depth;
            size_t curSize = q.size();
            for (size_t i = 0; i < curSize; ++i) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur->left == nullptr && cur->right == nullptr) {
                    return depth;
                }
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
            }
        }

        return depth;
    }
};

```


## 0226.翻转二叉树

链接：[0226.翻转二叉树](https://leetcode.cn/problems/invert-binary-tree/)

递归法：如果当前节点为空，返回空；反转左右节点；调换当前节点左右节点。可以前序也可以后序。这里采用后序。

迭代法：迭代法也由递归改迭代得到，由于前序迭代写法较为简单，这里迭代法使用前序。

```cpp
class Solution {
public:
    TreeNode* invertTree(TreeNode* root)
    {
        if (root == nullptr) {
            return nullptr;
        }
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
    TreeNode* invertTree2(TreeNode* root)
    {
        if (root == nullptr) {
            return nullptr;
        }
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* cur = stk.top();
            stk.pop();
            swap(cur->left, cur->right);
            if (cur->left) {
                stk.push(cur->left);
            }
            if (cur->right) {
                stk.push(cur->right);
            }
        }
        return root;
    }
};

```

## 0101.对称二叉树

链接：[0101.对称二叉树](https://leetcode.cn/problems/symmetric-tree/)

[0101.对称二叉树文字讲解](https://programmercarl.com/0101.%E5%AF%B9%E7%A7%B0%E4%BA%8C%E5%8F%89%E6%A0%91.html)

[0101.对称二叉树视频讲解](https://www.bilibili.com/video/BV1ue4y1Y7Mf/)

递归法：判断一个二叉树是否对称，需要判断两颗子树的两侧值是否相等。左子树的左侧和右子树的右侧（外侧），左子树的右侧和右子树的左侧（内侧）。
只有在确定两边子树是否对称的情况下，才能根据结果确定当前树是否对称，所以需要用后序遍历。
由于需要对两边子树的值进行判断，因此递归函数应该接收两个数节点。

迭代法1：一种思路是在分层迭代的基础上，获得一层元素，然后判断这一层是否对称，这种方法需要额外的与层宽度有关的空间。这里不用。

迭代法2：普通迭代，不需要分层，只不过一次处理两颗子树两边的节点。
对于节点的判断与递归法相似，都需要判断左子树的左侧和右子树的右侧（外侧），左子树的右侧和右子树的左侧（内侧）。

```cpp
class Solution {
public:
    bool isSymmetric(TreeNode* root)
    {
        if (root == nullptr) {
            return true;
        }
        bool res = compare(root->left, root->right);
        return res;
    }
    // 判断是否对称，需要判断两颗树的两侧，需要同时遍历两个树
    bool compare(TreeNode* left, TreeNode* right)
    {
        if (left == nullptr && right != nullptr) {
            return false;
        } else if (left != nullptr && right == nullptr) {
            return false;
        } else if (left == nullptr && right == nullptr) {
            return true;
        } else if (left->val != right->val) {
            return false;
        } else {
            // 外侧，左树的左侧和右树的右侧
            bool outside = compare(left->left, right->right);
            // 内侧，左树的右侧和右树的左侧
            bool inside = compare(left->right, right->left);
            // 在确定两棵子树是否是对称的之后，才能得到最终结果
            return outside && inside;
        }
    }
    // 迭代法
    bool isSymmetric2(TreeNode* root)
    {
        if (root == nullptr) {
            return true;
        }
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty()) {
            TreeNode* left = q.front();
            q.pop();
            TreeNode* right = q.front();
            q.pop();
            if (left == nullptr && right != nullptr) {
                // 如果一个为空一个不为空，不对称
                return false;
            } else if (left != nullptr && right == nullptr) {
                // 如果一个为空一个不为空，不对称
                return false;
            } else if (left == nullptr && right == nullptr) {
                // 都为空，对称，继续判断其它节点
                continue;
            } else if (left->val != right->val) {
                // 都不为空，但是值不相等，不对称
                return false;
            } else {
                // 都不为空，值相等，还得看两边子树是否对称
                // 外侧，左树的左侧和右树的右侧
                q.push(left->left);
                q.push(right->right);
                // 内侧，左树的右侧和右树的左侧
                q.push(left->right);
                q.push(right->left);
            }
        }
        return true;
    }
};

```

