#include "Utils.hpp"
#include <numeric>

using namespace std;

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val)
    {
        while (head) {
            if (head->val == val) {
                ListNode* d = head;
                head = head->next;
                delete d;
            } else {
                break;
            }
        }
        if (!head) {
            return head;
        }
        ListNode* cur = head;
        while (cur->next) {
            ListNode* temp = cur->next;
            if (temp->val == val) {
                cur->next = temp->next;
                delete temp;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};
