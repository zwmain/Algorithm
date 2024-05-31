// utf8文件头
#include "Node.h"

namespace zwn {

std::vector<std::string> Node::mTypeNames = { "UNKNOWN", "A", "B", "C", "D", "E" };

Node::Node()
{
}

Node::~Node()
{
}

NodePtr Node::create(char type)
{
    switch (type) {
    case 'A': {
        return std::make_shared<NodeA>();
    }
    case 'B': {
        return std::make_shared<NodeB>();
    }
    case 'C': {
        return std::make_shared<NodeC>();
    }
    case 'D': {
        return std::make_shared<NodeD>();
    }
    case 'E': {
        return std::make_shared<NodeE>();
    }
    default:
        break;
    }
    return NodePtr();
}

void Node::setPrev(NodePtr node)
{
    mPre = node;
}

void Node::setNext(NodePtr node)
{
    mNext = node;
}

NodePtr Node::prev()
{
    return mPre.lock();
}

NodePtr Node::next()
{
    return mNext;
}

NodeType Node::type() const
{
    return mType;
}

const std::string& Node::typeName() const
{
    return mTypeNames[static_cast<size_t>(mType)];
}

int Node::id() const
{
    return mId;
}

void Node::setId(int id)
{
    mId = id;
}

void Node::addPlayer(PlayerPtr player)
{
    mPlayers.insert(player);
}

void Node::removePlayer(PlayerPtr player)
{
    mPlayers.erase(player);
}

const std::set<PlayerPtr>& Node::players() const
{
    return mPlayers;
}

void Node::clearPlayers()
{
    mPlayers.clear();
}

NodeA::NodeA()
{
    mType = NodeType::A;
}

NodeA::~NodeA()
{
}

NodePtr NodeA::execResult(int step)
{
    if (!mNext) {
        return shared_from_this();
    }
    NodePtr res = mNext;
    for (int i = 1; i < step && res->next(); ++i) {
        res = res->next();
    }
    return res;
}

NodePtr NodeA::execResult()
{
    return shared_from_this();
}

NodeB::NodeB()
{
    mType = NodeType::B;
}

NodeB::~NodeB()
{
}

NodePtr NodeB::execResult(int step)
{
    if (!mNext) {
        return shared_from_this();
    }
    NodePtr res = mNext;
    for (int i = 1; i < step && res->next(); ++i) {
        res = res->next();
    }
    return res;
}

NodePtr NodeB::execResult()
{
    NodePtr pre = mPre.lock();
    if (pre) {
        return pre;
    }
    return shared_from_this();
}

NodeC::NodeC()
{
    mType = NodeType::C;
}

NodeC::~NodeC()
{
}

NodePtr NodeC::execResult(int step)
{
    if (mFlag) {
        mFlag = false;
        if (!mNext) {
            return shared_from_this();
        }
        NodePtr res = mNext;
        for (int i = 1; i < step && res->next(); ++i) {
            res = res->next();
        }
        return res;
    } else {
        mFlag = true;
        return shared_from_this();
    }
}

NodePtr NodeC::execResult()
{
    return shared_from_this();
}

NodeD::NodeD()
{
    mType = NodeType::D;
}

NodeD::~NodeD()
{
}

NodePtr NodeD::execResult(int step)
{
    if (!mNext) {
        return shared_from_this();
    }
    NodePtr res = mNext;
    for (int i = 1; i < step && res->next(); ++i) {
        res = res->next();
    }
    return res;
}

NodePtr NodeD::execResult()
{
    NodePtr cur = shared_from_this();
    while (cur->prev()) {
        cur = cur->prev();
    }
    return cur;
}

NodeE::NodeE()
{
    mType = NodeType::E;
}

NodeE::~NodeE()
{
}

NodePtr NodeE::execResult(int step)
{
    if (!mNext) {
        return shared_from_this();
    }
    NodePtr res = mNext;
    for (int i = 1; i < step && res->next(); ++i) {
        res = res->next();
    }
    return res;
}

NodePtr NodeE::execResult()
{
    NodePtr pre = mPre.lock();
    if (!pre) {
        return shared_from_this();
    }
    while (pre) {
        if (pre->type() == NodeType::E) {
            return pre;
        }
        pre = pre->prev();
    }
    return shared_from_this();
}

} // namespace zwn
