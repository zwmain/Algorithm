# 0160.相交链表

链接：[0160.相交链表](https://leetcode.cn/problems/intersection-of-two-linked-lists/)

思路：如图。沿着一条链表走完后，走到空时，走另一条链表。如果两条链表不相交，那么最后两个指针都为空。

![链表相交](lt0160.jpg)

```c++
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

```
