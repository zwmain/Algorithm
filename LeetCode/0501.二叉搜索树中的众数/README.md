# 0501.二叉搜索树中的众数

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
