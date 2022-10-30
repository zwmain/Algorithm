#include "main.h"
#include <iostream>

#if !defined(INPUT_PATH)
#define INPUT_PATH "./input.txt"
#endif // INPUT_PATH

int main()
{
    string fp(INPUT_PATH);
    auto input = zwn::inputIntArr(fp);
    vector<int> tarArr = { 9, 6, 6 };
    Solution s;
    for (size_t i = 0; i < input.size(); i += 1) {
        auto res = s.twoSum(input[i], tarArr[i]);
        zwn::outputIntArr(res);
    }
    return 0;
}
