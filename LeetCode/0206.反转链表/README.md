# 0206.反转链表

链接：[0206.反转链表](https://leetcode.cn/problems/reverse-linked-list/)

思路：维护三个指针：`prev`、`cur`、`latter`，分别指向前一个值、当前值、后一个值。
每次将`cur`的后继指向`prev`，然后按照`prev`、`cur`、`latter`的顺序更新指针，将他们后移一位。

即：

1. 将`cur`的后继指向`prev`
2. `prev`后移为`cur`
3. `cur`后移为`latter`
4. `latter`后移为`latter->next`

然后循环，直到`cur->next`为空时停止。退出时`cur`为最后一个节点，这个`cur`的后继还没更改为`prev`。
所以退出循环时还有一步`cur->next=pre`，此时`cur`就是逆序后的头节点。

核心代码概括为：

```c++
while (cur->next) {
    cur->next = prev;
    prev = cur;
    cur = latter;
    if (latter) {
        latter = latter->next;
    }
}
cur->next = prev;
```

源码：

```c++
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

```
