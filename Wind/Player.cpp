// utf8文件头
#include "Player.h"
#include "Dice.h"

namespace zwn
{

Player::Player()
{
}

Player::Player(const std::string& name)
:mName(name)
{
}

Player::~Player()
{
}
const std::string& Player::name() const
{
    return mName;
}

void Player::setCurrentNode(NodePtr node)
{
    mCurNode = node;
}

NodePtr Player::currentNode() const
{
    return mCurNode;
}

bool Player::isFinish() const
{
    if(!mCurNode) {
        return true;
    }
    auto ptr = mCurNode->next();
    return !ptr;
}

} // namespace zwn
