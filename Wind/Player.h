// utf8文件头
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <memory>

#include "Node.h"

namespace zwn {
class Player {
public:
    Player();
    Player(const std::string& name);
    ~Player();
    const std::string& name() const;
    void setCurrentNode(NodePtr node);
    NodePtr currentNode() const;
    bool isFinish() const;

private:
    std::string mName;
    NodePtr mCurNode;
};

typedef std::shared_ptr<Player> PlayerPtr;

} // namespace zwn

#endif
