#include "Utils.hpp"
#include <numeric>

using namespace std;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if (!head) {
            return head;
        }
        ListNode* vHead = new ListNode(0, head);
        ListNode* fast = head;
        ListNode* prev = vHead;
        for (int i = 1; i < n; ++i) {
            fast = fast->next;
        }
        while (fast->next) {
            fast = fast->next;
            prev = prev->next;
        }
        ListNode* d = prev->next;
        prev->next = d->next;
        delete d;
        ListNode* res = vHead->next;
        delete vHead;
        return res;
    }
};
