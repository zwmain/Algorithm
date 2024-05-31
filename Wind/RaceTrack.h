// utf8文件头
#ifndef RACETRACK_H
#define RACETRACK_H

#include <string>
#include <vector>
#include <map>

#include "Node.h"
#include "Player.h"

namespace zwn {
class RaceTrack {
public:
    RaceTrack(const std::string& nodeCfg, const std::vector<std::string>& playerCfg);
    ~RaceTrack();
    void logTrack();
    void startRace();

private:
    void sortPlayers();
    void logInitInfo();
    bool isAllFinish();

private:
    NodePtr mHead;
    NodePtr mEnd;
    std::vector<PlayerPtr> mPlayers;
    std::map<PlayerPtr, int> mScores;
};

} // namespace zwn

#endif
