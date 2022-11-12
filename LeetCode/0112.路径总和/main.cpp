#include "main.h"
#include "Utils.hpp"

#if !defined(INPUT_PATH)
#define INPUT_PATH "./input.txt"
#endif // INPUT_PATH

int main()
{
    string fp(INPUT_PATH);
    auto input = zwn::inputTreeNode(fp);
    vector<int> target = { 2, 22, 5 };
    Solution s;
    for (size_t i = 0; i < input.size(); ++i) {
        auto res = s.hasPathSum(input[i], target[i]);
        cout << res << endl;
    }
    return 0;
}
