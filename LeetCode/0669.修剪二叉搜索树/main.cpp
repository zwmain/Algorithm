#include "main.h"
#include <iostream>

#if !defined(INPUT_PATH)
#define INPUT_PATH "./input.txt"
#endif // INPUT_PATH

int main()
{
    string fp(INPUT_PATH);
    auto input = zwn::inputTreeNode(fp);
    vector<int> low = { 2 };
    vector<int> high = { 4 };
    Solution s;
    for (size_t i = 0; i < input.size(); ++i) {
        TreeNode* res = s.trimBST(input[i], low[i], high[i]);
        zwn::destroyTreeNode(res);
    }
    return 0;
}
