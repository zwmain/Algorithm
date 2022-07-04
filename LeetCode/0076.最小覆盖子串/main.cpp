#include "main.h"
#include <iostream>

int main()
{
    string fp(INPUT_FILE);
    auto str_arr = zwn::readFileAsLine(fp);
    Solution s;
    for (size_t i = 0; i < str_arr.size(); i += 2) {
        string res = s.minWindow(str_arr[i], str_arr[i + 1]);
        cout << res << endl;
    }
    return 0;
}
