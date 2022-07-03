#pragma once
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) :
        val(x), next(nullptr)
    {
    }
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if (l1 == nullptr && l2 == nullptr) return nullptr;
        if (l1 == nullptr && l2 != nullptr) return l2;
        if (l1 != nullptr && l2 == nullptr) return l1;
        // 设置头节点
        ListNode* res = nullptr;
        if (l1->val < l2->val) {
            res = l1;
            l1 = l1->next;
        }
        else {
            res = l2;
            l2 = l2->next;
        }
        res->next = nullptr;
        ListNode* cur = res;
        // 遍历两个链表，直到其中一个为空
        while (l1 && l2) {
            // 值小的那个下一个节点
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
            cur->next = nullptr;
        }
        // 当遍历结束时说明至少有一个链表为空
        // 那么将尾部直接指向那个未遍历完的链表即可
        l1 ? cur->next = l1 : cur->next = l2;
        return res;
    }
};