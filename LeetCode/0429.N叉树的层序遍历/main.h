#include "Utils.hpp"
#include <queue>

using namespace std;

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
