#include "Utils.hpp"
#include <numeric>

using namespace std;

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        ListNode* a = headA;
        ListNode* b = headB;
        while (a != b) {
            if (a) {
                a = a->next;
            } else {
                a = headB;
            }
            if (b) {
                b = b->next;
            } else {
                b = headA;
            }
        }
        return a;
    }
};
