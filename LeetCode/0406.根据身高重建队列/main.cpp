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
    Solution s;
    auto res = s.reconstructQueue(input);
    for (auto& arr : res) {
        zwn::outputIntArr(arr);
    }
    return 0;
}
