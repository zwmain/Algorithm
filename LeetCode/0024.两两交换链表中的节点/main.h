#include "Utils.hpp"
#include <numeric>

using namespace std;

class Solution {
public:
    ListNode* swapPairs(ListNode* head)
    {
        ListNode* vHead = new ListNode(0, head);
        ListNode* cur = vHead;
        while (cur->next && cur->next->next) {
            ListNode* n1 = cur->next;
            ListNode* n2 = n1->next;
            n1->next = n2->next;
            n2->next = n1;
            cur->next = n2;
            cur = n1;
        }
        ListNode* res = vHead->next;
        delete vHead;
        return res;
    }
};
