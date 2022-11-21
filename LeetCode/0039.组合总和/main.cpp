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
    vector<int> tar = { 7, 8, 1 };
    for (size_t i = 0; i < input.size(); ++i) {
        Solution s;
        auto res = s.combinationSum(input[i], tar[i]);
        for (auto& arr : res) {
            zwn::outputIntArr(arr);
        }
        cout << "------------------------" << endl;
    }
    return 0;
}
