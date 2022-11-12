#include "main.h"
#include "Utils.hpp"

#if !defined(INPUT_PATH)
#define INPUT_PATH "./input.txt"
#endif // INPUT_PATH

int main()
{
    string fp(INPUT_PATH);
    auto input = zwn::inputTreeNode(fp);
    Solution s;
    for (auto* t : input) {
        auto res = s.sumOfLeftLeaves(t);
        cout << res << endl;
        zwn::destroyTreeNode(t);
    }
    return 0;
}
