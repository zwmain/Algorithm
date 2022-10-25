#include "main.h"
#include "Utils.hpp"
#include <iostream>

#ifndef INPUT_PATH
#define INPUT_PATH "./input.txt"
#endif

int main()
{
    auto input = zwn::inputIntArr(INPUT_PATH);
    vector<int> index = { 9, 2, 5 };
    Solution s;
    for (int i = 0; i < input.size(); ++i) {
        auto res = s.search(input[i], index[i]);
        cout << res << endl;
        res = s.search2(input[i], index[i]);
        cout << res << endl;
    }
    return 0;
}
