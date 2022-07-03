#pragma once
#include<iostream>
#include<queue>
#include<stack>
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

class Solution {
public:
    bool isSymmetric(TreeNode* root)
    {
        if (root == NULL) return true;
        return check(root->left, root->right);
    }
    bool check(TreeNode* left, TreeNode* right)
    {
        if (left == NULL && right == NULL)
            return true;
        if (left == NULL || right == NULL)
            return false;
        return left->val == right->val && check(left->left, right->right) && check(left->right, right->left);
    }
};
//广度优先遍历，借助栈匹配对称元素
//bool isSymmetric(TreeNode* root) {
//    // 广度优先遍历
//    stack<TreeNode*> match;//借助栈匹配对称元素
//    queue<TreeNode*> nodes;
//    nodes.push(root);
//    while (!nodes.empty()) {
//        TreeNode* t = nodes.front();
//        if (t != NULL) {
//            nodes.push(t->left);
//            nodes.push(t->right);
//        }
//        nodes.pop();
//        if (match.empty()) {
//            match.push(t);
//        }
//        else {
//            TreeNode* p = match.top();
//            if (p == NULL && t == NULL) {
//                match.pop();
//            }
//            else if (p == NULL || t == NULL) {
//                match.push(t);
//            }
//            else if (p->val == t->val) {
//                match.pop();
//            }
//            else {
//                match.push(t);
//            }
//        }
//    }
//    if (match.size() == 1)
//        return true;
//    return false;
//}