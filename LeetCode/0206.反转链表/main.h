#include "Utils.hpp"
#include <numeric>

using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        if (!head) {
            return nullptr;
        }
        ListNode* prev = nullptr;
        ListNode* cur = head;
        ListNode* latter = cur->next;
        while (cur->next) {
            cur->next = prev;
            prev = cur;
            cur = latter;
            if (latter) {
                latter = latter->next;
            }
        }
        cur->next = prev;
        return cur;
    }
};
