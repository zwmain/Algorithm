#include "main.h"
#include <iostream>

int main()
{
    std::string fp(INPUT_FILE);
    auto arr = zwn::inputIntArr(fp);
    NumMatrix nx(arr);
    cout << nx.sumRegion(2, 1, 4, 3) << endl;
    cout << nx.sumRegion(1, 1, 2, 2) << endl;
    cout << nx.sumRegion(1, 2, 2, 4) << endl;
    return 0;
}
