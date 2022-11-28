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
    vector<int> k = { 1, 3, 2 };
    for (size_t i = 0; i < input.size(); ++i) {
        Solution s;
        auto res = s.largestSumAfterKNegations(input[i], k[i]);
        cout << res << endl;
    }
    return 0;
}
