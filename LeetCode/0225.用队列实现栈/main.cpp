#include "main.h"
#include <iostream>

#if !defined(INPUT_PATH)
#define INPUT_PATH "./input.txt"
#endif // INPUT_PATH

int main()
{
    MyStack s;
    s.push(1);
    s.push(2);
    int val = s.top();
    cout << val << endl;
    val = s.pop();
    cout << val << endl;
    cout << s.empty() << endl;
    return 0;
}
