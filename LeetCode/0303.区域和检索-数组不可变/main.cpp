#include "main.h"
#include <iostream>

int main()
{
    std::string fp(INPUT_FILE);
    auto arr = zwn::inputIntArr(fp);
    NumArray na(arr[0]);
    for (size_t i = 1; i < arr.size(); ++i) {
        int res = na.sumRange(arr[i][0], arr[i][1]);
        cout << res << endl;
    }
    return 0;
}
