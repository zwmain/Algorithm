#include "main.h"
#include <iostream>

#if !defined(INPUT_PATH)
#define INPUT_PATH "./input.txt"
#endif // INPUT_PATH

int main()
{
    string fp(INPUT_PATH);
    auto input = zwn::inputIntArr(fp);
    vector<int> ind = { 7, 4, 11 };
    Solution s;
    for (size_t i = 0; i < input.size(); ++i) {
        int res = s.minSubArrayLen(ind[i], input[i]);
        cout << res << endl;
    }
    return 0;
}
