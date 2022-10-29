# 0707.设计链表

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
