#include "main.h"
#include <iostream>

#if !defined(INPUT_PATH)
#define INPUT_PATH "./input.txt"
#endif // INPUT_PATH

int main()
{
    string fp(INPUT_PATH);
    auto input = zwn::inputIntArr(fp);
    Solution s;
    for (size_t i = 0; i < input.size(); ++i) {
        auto res = s.sortedSquares2(input[i]);
        cout << "输入：";
        zwn::outputIntArr(input[i]);
        cout << endl;
        cout << "输出：";
        zwn::outputIntArr(res);
        cout << endl;
    }
    return 0;
}
