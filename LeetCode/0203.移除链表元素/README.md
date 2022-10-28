# 0203.移除链表元素

链接：[0203.移除链表元素](https://leetcode.cn/problems/remove-linked-list-elements/)

思路：如果首位是目标值，那么删除首位，知道首位不为目标值为止。
由于首位不是目标值，那么每次只需要看当前位置的下一个即可。
如果下一个值为目标值，那么临时存储下一个节点，将当前节点指向下一个的下一个节点，删除临时存储的节点。

主要保证链表的连续性。

```c++
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

```
