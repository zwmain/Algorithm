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
    string fd(INPUT_DIR);
    string fp1 = fd + "input1.txt";
    string fp2 = fd + "input2.txt";
    auto gas = zwn::inputIntArr(fp1);
    auto cost = zwn::inputIntArr(fp2);
    for (size_t i = 0; i < gas.size(); ++i) {
        Solution s;
        auto res = s.canCompleteCircuit(gas[i], cost[i]);
        cout << res << endl;
    }
    return 0;
}
