#include "main.h"

#if !defined(INPUT_PATH)
#define INPUT_PATH "./input.txt"
#endif // INPUT_PATH

int main()
{
    string fp(INPUT_PATH);
    auto input = zwn::inputIntArr(fp);
    vector<int> tarArr = { 0, 8, 0 };
    Solution slu;
    for (size_t i = 0; i < input.size(); ++i) {
        auto res = slu.fourSum(input[i], tarArr[i]);
        for (auto& arr : res) {
            zwn::outputIntArr(arr);
        }
        cout << "--------------------" << endl;
    }
    return 0;
}
