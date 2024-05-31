// utf8文件头
#include "Dice.h"

namespace zwn {

Dice::Dice()
    : mDis(1, 6)
{
    std::random_device rd;
    mEng.seed(rd());
}

Dice::~Dice()
{
}

Dice* Dice::instance()
{
    static Dice dice;
    return &dice;
}

int Dice::value()
{
    return mDis(mEng);
}

int Dice::value(int range)
{
    if (range < 1) {
        range = 1;
    }
    std::uniform_int_distribution<int> tempDis(1, range);
    return tempDis(mEng);
}

} // namespace zwn
