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
    for (size_t i = 0; i < input.size(); i += 4) {
        auto res = s.fourSumCount(input[i], input[i + 1], input[i + 2], input[i + 3]);
        cout << res << endl;
    }
    return 0;
}
