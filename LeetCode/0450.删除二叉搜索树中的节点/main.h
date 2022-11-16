#include "Utils.hpp"

using namespace std;

class Solution {
public:
    // 返回值是删除节点后，子树新的根节点
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        // 没找到删除的节点
        if (root == nullptr) {
            return nullptr;
        }

        if (root->val == key) {
            if (root->left == nullptr && root->right == nullptr) {
                // 左为空，右为空，直接删除
                delete root;
                // 递归前需要接收新节点
                return nullptr;
            } else if (root->left != nullptr && root->right == nullptr) {
                // 左不空，右为空，父节点直接指向左节点
                TreeNode* left = root->left;
                delete root;
                return left;
            } else if (root->left == nullptr && root->right != nullptr) {
                // 左为空，右不空，父节点直接指向右节点
                TreeNode* right = root->right;
                delete root;
                return right;
            } else {
                // 左不空，右不空，选择左右节点其中一个继位。这里选择右子树继位
                TreeNode* left = root->left;
                TreeNode* right = root->right;
                delete root;
                // 寻找右子树的最左侧，插入左子树
                TreeNode* ins = right;
                while (ins->left) {
                    ins = ins->left;
                }
                ins->left = left;
                return right;
            }
        } else if (root->val > key) {
            // 当前子树需要接收新子树根节点
            root->left = deleteNode(root->left, key);
        } else {
            root->right = deleteNode(root->right, key);
        }

        return root;
    }
};
