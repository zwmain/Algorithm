#include "main.h"
#include "Utils.hpp"
#include <iostream>

#if !defined(INPUT_PATH)
#define INPUT_PATH "./input.txt"
#endif // INPUT_PATH

#if !defined(INPUT_DIR)
#define INPUT_DIR "./"
#endif // INPUT_PATH

int main()
{
    string fp(INPUT_PATH);
    auto input = zwn::inputIntArr(fp);
    vector<int> target = { 3, 1 };
    for (size_t i = 0; i < input.size(); ++i) {
        Solution s;
        auto res = s.findTargetSumWays(input[i], target[i]);
        cout << res << endl;
    }
    return 0;
}
