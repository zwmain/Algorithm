#include "main.h"

#if !defined(INPUT_PATH)
#define INPUT_PATH "./input.txt"
#endif // INPUT_PATH

int main()
{
    string fp(INPUT_PATH);
    auto input = zwn::inputIntArr(fp);
    Solution slu;
    for (size_t i = 0; i < input.size(); ++i) {
        auto res = slu.threeSum(input[i]);
        for (auto& arr : res) {
            zwn::outputIntArr(arr);
        }
        cout << "--------------------" << endl;
    }
    return 0;
}
