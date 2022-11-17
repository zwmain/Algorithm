#include "Utils.hpp"

using namespace std;

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high)
    {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->val < low) {
            // 修剪当前节点的右子树
            // 不能直接返回右子树，因为右子树的左子树里还可能存在小于low的数
            TreeNode* right = trimBST(root->right, low, high);
            // 删除当前节点的左子树
            destroyTree(root->left);
            // 删除当前节点
            delete root;
            return right;
        } else if (root->val > high) {
            // 修建当前节点的左子树
            // 不能直接返回左子树，因为左子树的右子树里还可能存在大于high的数
            TreeNode* left = trimBST(root->left, low, high);
            destroyTree(root->right);
            delete root;
            return left;
        } else {
            // 如果当前节点在区间内
            // 当前左子树等于修剪后的左子树
            root->left = trimBST(root->left, low, high);
            // 当前右子树等于修剪后的右子树
            root->right = trimBST(root->right, low, high);
            return root;
        }
    }

    void destroyTree(TreeNode* root)
    {
        if (root == nullptr) {
            return;
        }
        destroyTree(root->left);
        destroyTree(root->right);
        delete root;
    }
};
