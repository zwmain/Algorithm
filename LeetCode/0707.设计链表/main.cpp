#include "main.h"
#include <iostream>

#if !defined(INPUT_PATH)
#define INPUT_PATH "./input.txt"
#endif // INPUT_PATH

int main()
{
    MyLinkedList linkedList;
    linkedList.addAtHead(1);
    linkedList.addAtTail(3);
    linkedList.addAtIndex(1, 2); //链表变为1-> 2-> 3
    linkedList.get(1); //返回2
    linkedList.deleteAtIndex(1); //现在链表是1-> 3
    linkedList.get(1); //返回3

    return 0;
}
