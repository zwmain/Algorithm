#include "main.h"
#include <iostream>

#if !defined(INPUT_PATH)
#define INPUT_PATH "./input.txt"
#endif // INPUT_PATH

int main()
{
    string fp(INPUT_PATH);
    auto input = zwn::inputStr(fp);
    Solution s;
    auto res = s.evalRPN(input);
    // -2147483648
    cout << res << endl;
    return 0;
}
