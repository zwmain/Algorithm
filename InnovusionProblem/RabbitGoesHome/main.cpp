#include "GoHome.hpp"
#include <iostream>

int main()
{
    Rabbit r(3, 3, { { 1, 1 } });
    size_t num = r.goHomeA();
    std::cout << num << std::endl;
    return 0;
}
