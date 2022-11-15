#include "Utils.hpp"

using namespace std;

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
