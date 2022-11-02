#include "main.h"
#include <iostream>

#if !defined(INPUT_PATH)
#define INPUT_PATH "./input.txt"
#endif // INPUT_PATH

int main()
{
    string fp(INPUT_PATH);
    auto input = zwn::inputStr(fp);
    vector<int> k = { 2, 2, 2 };
    Solution s;
    for (size_t i = 0; i < input.size(); ++i) {
        auto res = s.reverseStr(input[i], k[i]);
        cout << res << endl;
    }
    return 0;
}
