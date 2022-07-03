#pragma once
#include<iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head)
    {
        if (head == nullptr) {
            return false;
        }
        //快慢指针
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};
//暴力解法
//while (head) {
//    ListNode* start = head;
//    while (start->next) {
//        if (start->next == head)
//            return true;
//        start = start->next;
//    }
//    head = head->next;
//}
//return false;
