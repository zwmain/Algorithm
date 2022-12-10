/**
 * @file Utils.hpp
 * @author zwmain
 * @brief 刷题辅助工具库
 * @version 1.0
 * @date 2022-06-04
 *
 * @copyright Copyright (c) 2022 zwmain
 *
 */

#ifndef _UTILS_HPP_
#define _UTILS_HPP_

#include "../../CppDemo/MyUtils/MyUtils.hpp"
#include <iostream>
#include <queue>

/**
 * @brief 链表节点结构体
 *
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode()
        : val(0)
        , next(nullptr)
    {
    }
    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }
    ListNode(int x, ListNode* next)
        : val(x)
        , next(next)
    {
    }
};

/**
 * @brief 二叉树节点结构体
 *
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
        : val(0)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x)
        , left(left)
        , right(right)
    {
    }
};

/**
 * @brief N叉树节点
 *
 */
class NaryTreeNode {
public:
    int val;
    std::vector<NaryTreeNode*> children;

    NaryTreeNode() { }

    NaryTreeNode(int _val)
    {
        val = _val;
    }

    NaryTreeNode(int _val, std::vector<NaryTreeNode*> _children)
    {
        val = _val;
        children = _children;
    }
};

/**
 * @brief 二叉树，带next节点
 *
 */
class NextTreeNode {
public:
    int val;
    NextTreeNode* left;
    NextTreeNode* right;
    NextTreeNode* next;

    NextTreeNode()
        : val(0)
        , left(NULL)
        , right(NULL)
        , next(NULL)
    {
    }

    NextTreeNode(int _val)
        : val(_val)
        , left(NULL)
        , right(NULL)
        , next(NULL)
    {
    }

    NextTreeNode(int _val, NextTreeNode* _left, NextTreeNode* _right, NextTreeNode* _next)
        : val(_val)
        , left(_left)
        , right(_right)
        , next(_next)
    {
    }
};

namespace zwn {

/**
 * @brief 从文件中读取数组
 *
 * @param fp 文件路径
 * @return 整数数组
 */
std::vector<std::vector<int>> inputIntArr(const std::string& fp);

/**
 * @brief 输出数组
 *
 * @param str_arr 字符串数组
 */
void outputStrArr(const std::vector<std::string>& str_arr);

/**
 * @brief 输入链表
 *
 * @param fp 文件路径
 * @return 链表数组
 */
std::vector<ListNode*> inputList(const std::string& fp);

/**
 * @brief 清除链表
 *
 * @param list_arr 链表数组
 */
void destroyListArr(std::vector<ListNode*>& list_arr);

/**
 * @brief 清除链表
 *
 * @param head 链表头节点
 */
void destroyList(ListNode* head);

/**
 * @brief 输出链表
 *
 * @param head 链表头节点
 */
void outputList(ListNode* head);

/**
 * @brief 输入整数
 *
 * @param fp 文件路径
 * @return 整数数组
 */
std::vector<int> inputInt(const std::string& fp);

/**
 * @brief 输出数组
 *
 * @tparam T 可以直接cout的类型
 * @param arr 待输出的数组
 */
template <typename T>
void outputArr(const std::vector<T>& arr);

/**
 * @brief 输出整数数组
 *
 * @param arr 整数数组
 */
void outputIntArr(const std::vector<int>& arr);

/**
 * @brief 输入字符串
 *
 * @param fp 文件路径
 * @return 字符串数组
 */
std::vector<std::string> inputStr(const std::string& fp);

/**
 * @brief 根据字符串数组解析二叉树
 *
 * @param arr 层序遍历的二叉树节点
 * @return TreeNode* 二叉树根节点
 */
TreeNode* parseTreeNode(const std::vector<std::string>& arr);

/**
 * @brief 输入二叉树
 *
 * @param fp 文件路径
 * @return std::vector<TreeNode*> 二叉树数组
 */
std::vector<TreeNode*> inputTreeNode(const std::string& fp);

/**
 * @brief 递归析构二叉树
 *
 * @param root 二叉树根节点
 */
void destroyTreeNode(TreeNode* root);

/**
 * @brief 层序输出二叉树
 *
 * @param root 二叉树根节点
 */
void outputTreeNode(TreeNode* root);

// ----------------------------------------------------------------------------

std::vector<std::vector<int>> inputIntArr(const std::string& fp)
{
    std::vector<std::vector<int>> res;
    auto lines = readFileAsLine(fp);
    for (auto& line : lines) {
        auto arr = splitString(line, ",");
        std::vector<int> num_arr;
        for (auto& num : arr) {
            int val = std::stoi(num);
            num_arr.push_back(val);
        }
        res.push_back(std::move(num_arr));
    }
    return res;
}

void outputStrArr(const std::vector<std::string>& str_arr)
{
    bool is_first = true;
    std::cout << '[';
    for (auto& s : str_arr) {
        if (is_first) {
            std::cout << '"';
            std::cout << s;
            is_first = false;
        } else {
            std::cout << ",\"";
            std::cout << s;
        }
        std::cout << '"';
    }
    std::cout << ']' << std::endl;
}

std::vector<ListNode*> inputList(const std::string& fp)
{
    std::vector<ListNode*> res;
    auto arrs = inputIntArr(fp);
    for (auto& line : arrs) {
        ListNode* p_node = nullptr;
        ListNode* p_cur = nullptr;
        for (int i : line) {
            if (p_node) {
                p_cur->next = new ListNode(i);
                p_cur = p_cur->next;
            } else {
                p_node = new ListNode(i);
                p_cur = p_node;
            }
        }
        res.push_back(p_node);
    }
    return res;
}

void destroyListArr(std::vector<ListNode*>& list_arr)
{
    for (ListNode* p_node : list_arr) {
        while (p_node) {
            ListNode* d = p_node;
            p_node = p_node->next;
            delete d;
        }
    }
    list_arr.clear();
}

void destroyList(ListNode* head)
{
    while (head) {
        ListNode* d = head;
        head = head->next;
        delete d;
    }
}

void outputList(ListNode* head)
{
    if (!head) {
        return;
    }
    std::cout << head->val;
    head = head->next;
    while (head) {
        std::cout << ", " << head->val;
        head = head->next;
    }
    std::cout << std::endl;
}

std::vector<int> inputInt(const std::string& fp)
{
    std::vector<int> res;
    auto str_arr = readFileAsLine(fp);
    for (auto& line : str_arr) {
        res.push_back(std::stoi(line));
    }
    return res;
}

template <typename T>
void outputArr(const std::vector<T>& arr)
{
    bool is_first = true;
    std::cout << '[';
    for (const auto& i : arr) {
        if (is_first) {
            std::cout << i;
            is_first = false;
        } else {
            std::cout << ", " << i;
        }
    }
    std::cout << ']' << std::endl;
}

void outputIntArr(const std::vector<int>& arr)
{
    bool is_first = true;
    std::cout << '[';
    for (auto i : arr) {
        if (is_first) {
            std::cout << i;
            is_first = false;
        } else {
            std::cout << ", " << i;
        }
    }
    std::cout << ']' << std::endl;
}

std::vector<std::string> inputStr(const std::string& fp)
{
    return readFileAsLine(fp);
}

TreeNode* parseTreeNode(const std::vector<std::string>& arr)
{
    if (arr.empty()) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(stoi(arr[0]));
    std::queue<TreeNode*> q;
    q.push(root);
    for (size_t i = 1; i < arr.size(); ++i) {
        if (q.empty()) {
            break;
        }
        TreeNode* cur = q.front();
        q.pop();
        if (arr[i] == "null") {
            cur->left = nullptr;
        } else {
            cur->left = new TreeNode(stoi(arr[i]));
            q.push(cur->left);
        }
        ++i;
        if (i >= arr.size()) {
            break;
        }
        if (arr[i] == "null") {
            cur->right = nullptr;
        } else {
            cur->right = new TreeNode(stoi(arr[i]));
            q.push(cur->right);
        }
    }
    return root;
}

std::vector<TreeNode*> inputTreeNode(const std::string& fp)
{
    std::vector<TreeNode*> res;
    auto lines = readFileAsLine(fp);
    for (auto& s : lines) {
        auto arr = splitString(s, ",");
        TreeNode* root = parseTreeNode(arr);
        res.push_back(root);
    }
    return res;
}

void destroyTreeNode(TreeNode* root)
{
    if (root == nullptr) {
        return;
    }
    destroyTreeNode(root->left);
    destroyTreeNode(root->right);
    delete root;
}

void outputTreeNode(TreeNode* root)
{
    std::string res("[");
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* cur = q.front();
        q.pop();
        if (cur == nullptr) {
            res += "null";
        } else {
            // 叶节点的两个空子树不会被加入队列
            if (!(cur->left == nullptr && cur->right == nullptr)) {
                q.push(cur->left);
                q.push(cur->right);
            }
            res += std::to_string(cur->val);
        }
        res += ",";
    }
    if (res[res.size() - 1] == ',') {
        res.pop_back();
    }
    res += "]";
    std::cout << res << std::endl;
}

} // namespace zwn

#endif
