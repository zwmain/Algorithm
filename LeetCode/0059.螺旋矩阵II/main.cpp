#include "main.h"
#include <iostream>

#if !defined(INPUT_PATH)
#define INPUT_PATH "./input.txt"
#endif // INPUT_PATH

int main()
{
    string fp(INPUT_PATH);
    auto input = zwn::inputInt(fp);
    Solution s;
    for (size_t i = 0; i < input.size(); ++i) {
        auto res = s.generateMatrix(input[i]);
        cout << "[" << endl;
        for (auto& arr : res) {
            zwn::outputIntArr(arr);
        }
        cout << "]" << endl;
    }
    return 0;
}
