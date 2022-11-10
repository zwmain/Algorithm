#include "main.h"
#include <iostream>

#if !defined(INPUT_PATH)
#define INPUT_PATH "./input.txt"
#endif // INPUT_PATH

int main()
{
    string fp(INPUT_PATH);
    auto input = zwn::inputTreeNode(fp);
    Solution s;
    for (auto& t : input) {
        auto res = s.preorderTraversal(t);
        zwn::outputIntArr(res);
        zwn::destroyTreeNode(t);
    }
    return 0;
}
