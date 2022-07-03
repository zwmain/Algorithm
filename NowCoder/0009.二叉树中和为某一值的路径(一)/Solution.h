#pragma once
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL)
    {
    }
};

//class Solution {
//public:
//    bool hasPathSum(TreeNode* root, int sum) {
//        if (root == NULL) {
//            return false;
//        }
//        target = sum;
//        int path_sum = root->val;
//        if (root->left == NULL && root->right == NULL)
//            return root->val == sum;
//        if (root->left != NULL && dfs(root->left, path_sum))
//            return true;
//        return root->right != NULL && dfs(root->right, path_sum);
//    }
//    bool dfs(TreeNode* node, int path_sum) {
//        path_sum += node->val;
//        if (node->left != NULL && dfs(node->left, path_sum))
//            return true;
//        if (node->right != NULL && dfs(node->right, path_sum))
//            return true;
//        return path_sum == target;
//    }
//
//private:
//    int target = 0;
//};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum)
    {
        if (root == NULL) {
            return false;
        }
        target = sum;
        // 路径和的初始值为0
        return dfs(root, 0);
    }
    bool dfs(TreeNode* node, int path_sum)
    {
        if (nullptr == node) {
            return false;
        }
        // 路径和加上当前节点值
        path_sum += node->val;
        // 路径遍历结束，判断路径和是否等于目标和，返回结果
        // 路径结束的条件为：节点本身为空或者节点的两个子节点都为空
        if (node->left == nullptr && node->right == nullptr) {
            return path_sum == target;
        }
        // 遍历左子树，如果左子树成功，就无需继续了
        if (nullptr != node->left && dfs(node->left, path_sum)) {
            return true;
        }
        // 遍历右子树
        return nullptr != node->right && dfs(node->right, path_sum);
    }

private:
    int target = 0;
};
