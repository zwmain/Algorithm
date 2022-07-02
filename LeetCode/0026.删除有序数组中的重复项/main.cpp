#include "main.h"
#include <iostream>

int main()
{
    std::string fp(INPUT_FILE);
    auto arr = zwn::inputIntArr(fp);
    Solution s;
    for (auto& i : arr) {
        cout << s.removeDuplicates(i) << '\t';
        zwn::outputIntArr(i);
    }
    return 0;
}
