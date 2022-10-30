# 0019.删除链表的倒数第N个结点

链接：[0019.删除链表的倒数第N个结点](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/)

思路：删除倒数第N个节点，一定要找到倒数第N个节点的前一个节点。借助虚拟头节点，可以方便的定位待删除节点的前一个节点。借助双指针，一个指针从head开始先走N-1步（倒数第N，N是从1开始的）。
然后另一个指针从vHead开始，两个指针同时后移，直到快指针指向最后一个元素。此时慢指针指向倒数第N的节点的前一个节点。

```c++
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

```
