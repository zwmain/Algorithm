# Day03.移除链表元素、反转链表

## 0203.移除链表元素

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

思路2：设置虚拟头节点，可以精简逻辑。

## 0707.设计链表

链接：[0707.设计链表](https://leetcode.cn/problems/design-linked-list/)

这道题的重点是虚拟头节点和尾节点的维护

```c++
class MyLinkedList {
public:
    MyLinkedList()
    {
        _vHead = new ListNode;
        _vHead->val = -1;
        _vHead->next = nullptr;
    }

    ~MyLinkedList()
    {
        while (_vHead) {
            ListNode* d = _vHead;
            _vHead = _vHead->next;
            delete d;
        }
    }

    int get(int index)
    {
        ListNode* cur = _vHead->next;
        for (int i = 0; i < index && cur; ++i) {
            cur = cur->next;
        }
        return cur == nullptr ? -1 : cur->val;
    }

    void addAtHead(int val)
    {
        ListNode* curHead = _vHead->next;
        ListNode* h = new ListNode;
        h->val = val;
        h->next = curHead;
        if (curHead == nullptr) {
            _tail = h;
        }
        _vHead->next = h;
    }

    void addAtTail(int val)
    {
        ListNode* n = new ListNode;
        n->val = val;
        n->next = nullptr;
        if (_tail) {
            _tail->next = n;
            _tail = _tail->next;
        } else {
            _vHead->next = n;
            _tail = n;
        }
    }

    void addAtIndex(int index, int val)
    {
        if (index < 0) {
            addAtHead(val);
            return;
        }
        ListNode* prev = _vHead;
        for (int i = 0; i < index && prev; ++i) {
            prev = prev->next;
        }
        if (!prev) {
            return;
        }
        ListNode* r = prev->next;
        ListNode* n = new ListNode;
        n->val = val;
        n->next = r;
        prev->next = n;
        if (r == nullptr) {
            _tail = n;
        }
    }

    void deleteAtIndex(int index)
    {
        ListNode* prev = _vHead;
        for (int i = 0; i < index && prev; ++i) {
            prev = prev->next;
        }
        if (prev && prev->next) {
            ListNode* d = prev->next;
            prev->next = d->next;
            if (prev->next == nullptr) {
                _tail = prev == _vHead ? nullptr : prev;
            }
            delete d;
        }
    }

private:
    ListNode* _vHead = nullptr;
    // ListNode* _head = nullptr;
    ListNode* _tail = nullptr;
};

```

## 0206.反转链表

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

