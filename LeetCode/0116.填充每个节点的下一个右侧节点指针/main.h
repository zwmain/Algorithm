#include "Utils.hpp"
#include <queue>

using namespace std;

typedef NextTreeNode Node;

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
