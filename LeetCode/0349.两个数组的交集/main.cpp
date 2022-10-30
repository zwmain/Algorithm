#include "main.h"
#include <iostream>

#if !defined(INPUT_PATH)
#define INPUT_PATH "./input.txt"
#endif // INPUT_PATH

int main()
{
    string fp(INPUT_PATH);
    auto input = zwn::inputIntArr(fp);
    Solution s;
    for (size_t i = 0; i < input.size(); i += 2) {
        auto res = s.intersection(input[i], input[i + 1]);
        zwn::outputIntArr(res);
    }
    return 0;
}
