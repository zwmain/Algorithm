#include "main.h"
#include <iostream>

#if !defined(INPUT_PATH)
#define INPUT_PATH "./input.txt"
#endif // INPUT_PATH

int main()
{
    string fp(INPUT_PATH);
    auto input = zwn::inputList(fp);
    vector<int> N = { 2, 1, 1 };
    Solution s;
    for (size_t i = 0; i < input.size(); ++i) {
        ListNode* res = s.removeNthFromEnd(input[i], N[i]);
        zwn::outputList(res);
        zwn::destroyList(res);
    }
    return 0;
}
