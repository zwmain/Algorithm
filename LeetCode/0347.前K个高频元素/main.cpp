#include "main.h"
#include <iostream>

#if !defined(INPUT_PATH)
#define INPUT_PATH "./input.txt"
#endif // INPUT_PATH

int main()
{
    string fp(INPUT_PATH);
    auto input = zwn::inputIntArr(fp);
    vector<int> k = { 2, 1 };
    Solution s;
    for (size_t i = 0; i < input.size(); ++i) {
        auto res = s.topKFrequent(input[i], k[i]);
        zwn::outputIntArr(res);
    }
    return 0;
}
