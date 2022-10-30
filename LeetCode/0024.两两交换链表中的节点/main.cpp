#include "main.h"
#include <iostream>

#if !defined(INPUT_PATH)
#define INPUT_PATH "./input.txt"
#endif // INPUT_PATH

int main()
{
    string fp(INPUT_PATH);
    auto input = zwn::inputList(fp);
    Solution s;
    for (size_t i = 0; i < input.size(); ++i) {
        ListNode* res = s.swapPairs(input[i]);
        zwn::outputList(res);
        zwn::destroyList(res);
    }
    return 0;
}
