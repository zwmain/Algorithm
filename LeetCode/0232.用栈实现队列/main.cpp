#include "main.h"
#include <iostream>

#if !defined(INPUT_PATH)
#define INPUT_PATH "./input.txt"
#endif // INPUT_PATH

int main()
{
    MyQueue q;
    q.push(1);
    q.push(2);
    int val = q.peek();
    cout << val << endl;
    val = q.pop();
    cout << val << endl;
    cout << q.empty() << endl;
    return 0;
}
