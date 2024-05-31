// utf8文件头
#ifndef DEICE_H
#define DEICE_H

#include <random>

namespace zwn {
class Dice {
private:
    Dice();

public:
    ~Dice();
    static Dice* instance();
    int value();
    int value(int range);

private:
    Dice(const Dice&) = delete;
    Dice(Dice&&) = delete;

private:
    std::default_random_engine mEng;
    std::uniform_int_distribution<int> mDis;
};

} // namespace zwn

#endif
