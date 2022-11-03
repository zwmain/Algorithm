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
    for (size_t i = 0; i < input.size(); i += 2) {
        auto res = s.strStr(input[i], input[i + 1]);
        cout << res << endl;
    }
    return 0;
}
