#include "main.h"
#include "Utils.hpp"
#include <iostream>

#if !defined(INPUT_PATH)
#define INPUT_PATH "./input.txt"
#endif // INPUT_PATH

int main()
{
    string fp(INPUT_PATH);
    auto input = zwn::inputIntArr(fp);
    for (size_t i = 0; i < input.size(); i += 1) {
        Solution s;
        auto res = s.nextGreaterElements(input[i]);
        zwn::outputIntArr(res);
    }
    return 0;
}
