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
    auto input = zwn::inputStr(fp);
    string s = "leetcode";
    Solution slu;
    auto res = slu.wordBreak(s, input);
    cout << res << endl;
    return 0;
}
