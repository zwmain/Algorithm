#include "main.h"
#include "Utils.hpp"
#include <iostream>

#if !defined(INPUT_PATH)
#define INPUT_PATH "./input.txt"
#endif // INPUT_PATH

int main()
{
    string fp(INPUT_PATH);
    auto input = zwn::inputInt(fp);
    for (size_t i = 0; i < input.size(); ++i) {
        Solution s;
        auto res = s.solveNQueens(input[i]);
        for (auto& arr : res) {
            zwn::outputStrArr(arr);
        }
        cout << "----------------------------" << endl;
    }
    return 0;
}
