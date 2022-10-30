# 0024.两两交换链表中的节点

链接：[0024.两两交换链表中的节点](https://leetcode.cn/problems/swap-nodes-in-pairs/)

思路：借助虚拟头节点。因为是交换两个节点，所以需要借助更前一个节点来完成。

```c++
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

```
