#include "main.h"
#include <iostream>

int main()
{
    string fp(INPUT_FILE);
    auto arr = zwn::inputIntArr(fp);
    vector<int> inp = { 9, 6, -1 };
    Solution s;
    for (size_t i = 0; i < inp.size(); ++i) {
        zwn::outputIntArr(s.twoSum(arr[i], inp[i]));
    }
    return 0;
}
