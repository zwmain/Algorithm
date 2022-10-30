#include "Utils.hpp"
#include <numeric>

using namespace std;

class Solution {
public:
    ListNode* detectCycle(ListNode* head)
    {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            // 相遇
            if (fast == slow) {
                // 一个指针从相遇处出发
                ListNode* z = fast;
                // 一个指针从头节点出发
                ListNode* h = head;
                while (z != h) {
                    z = z->next;
                    h = h->next;
                }
                // 两个指针相遇的地方就是环的入口点
                return z;
            }
        }
        return nullptr;
    }
};
