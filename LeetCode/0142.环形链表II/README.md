# 0142.环形链表II

链接：[0142.环形链表II](https://leetcode.cn/problems/intersection-of-two-linked-lists/)

解题思路参考：[代码随想录](https://programmercarl.com/0142.%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8II.html)

判断链表是否有环：使用快慢指针法，分别定义 fast 和 slow 指针，从头结点出发，fast指针每次移动两个节点，slow指针每次移动一个节点，如果 fast 和 slow指针在途中相遇 ，说明这个链表有环。

环的入口：如图。

![环的入口](lt0142.png)

假设从头结点到环形入口节点的节点数为x。环形入口节点到fast指针与slow指针相遇节点节点数为y。从相遇节点再到环形入口节点节点数为z。

相遇时：slow指针走过的节点数为：`x+y`，fast走过的节点数为`x+y+n(y+z)`。fast可能已经在圈内走了n圈，然后才和slow相遇。

因为slow每次走一个节点，fast每次走两个节点。那么fast走的节点数目时slow的两倍。即，`2(x+y)=x+y+n(y+z)`。

化简：`x+y=n(y+z)`。

因为需要知道，环的入口，所以需要知道环的入口相对于头节点的位置，才能定位入口节点。即需要x。

那么式子可以化为：`x=n(y+z)-y`。

进而化为：`x=(n-1)(y+z)+z`。这个式子意味着，当快慢指针相遇时，一个指针从头节点出发，一个从相遇位置出发，在相遇节点出发的那个指针走了n-1圈加z步后，头节点出发的指针正好走了x步。
二者相遇，相遇处就是环的入口处。

```c++
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

```
