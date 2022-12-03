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
    auto input = zwn::inputInt(fp);
    for (size_t i = 0; i < input.size(); ++i) {
        Solution s;
        auto res = s.climbStairs(input[i]);
        cout << res << endl;
    }
    return 0;
}
