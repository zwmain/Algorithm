// utf8文件头
#include <iostream>
#include "RaceTrack.h"

int main()
{
    std::string nodeCfg = "AABACAADAAEAAAAEBACA";
    std::vector<std::string> playerCfg = { "甲", "乙", "丙" };
    zwn::RaceTrack raceTrack(nodeCfg, playerCfg);
    raceTrack.logTrack();
    raceTrack.startRace();
    return 0;
}

