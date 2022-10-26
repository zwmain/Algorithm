#include "main.h"
#include <iostream>

#if !defined(INPUT_PATH)
#define INPUT_PATH "./input.txt"



#endif // INPUT_PATH


int main()
{
    string fp(INPUT_PATH);
    auto arr = zwn::inputIntArr(fp);
    vector<int> inp = { 3, 2, 2, 0 };
    Solution s;
    for (size_t i = 0; i < inp.size(); ++i) {
        cout << s.removeElement(arr[i], inp[i]);
        zwn::outputIntArr(arr[i]);
    }
    return 0;
}
