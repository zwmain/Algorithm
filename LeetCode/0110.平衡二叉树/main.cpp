#include "main.h"
#include "Utils.hpp"
#include <iostream>
#include <string>

#if !defined(INPUT_PATH)
#define INPUT_PATH "./input.txt"
#endif // INPUT_PATH

int main()
{
    string fp(INPUT_PATH);
    auto input = zwn::inputTreeNode(fp);
    Solution s;
    for (auto* t : input) {
        bool res = s.isBalanced(t);
        cout << res << endl;
        zwn::destroyTreeNode(t);
    }
    return 0;
}
