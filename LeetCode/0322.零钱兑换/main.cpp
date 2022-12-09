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
    vector<int> amount = { 11, 3, 0 };
    for (int i = 0; i < input.size(); ++i) {
        Solution s;
        auto res = s.coinChange(input[i], amount[i]);
        cout << res << endl;
    }
    return 0;
}
