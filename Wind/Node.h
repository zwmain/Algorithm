// utf8文件头
#ifndef NODE_H
#define NODE_H

#include <memory>
#include <string>
#include <vector>
#include <set>

namespace zwn {
enum class NodeType {
    UNKNOWN,
    A,
    B,
    C,
    D,
    E
};

class Player;
typedef std::shared_ptr<Player> PlayerPtr;

class Node;
typedef std::shared_ptr<Node> NodePtr;

class Node : public std::enable_shared_from_this<Node> {
public:
    Node();
    ~Node();
    static NodePtr create(char type);
    void setPrev(NodePtr node);
    void setNext(NodePtr node);
    NodePtr prev();
    NodePtr next();
    NodeType type() const;
    const std::string& typeName() const;
    int id() const;
    void setId(int id);
    void addPlayer(PlayerPtr player);
    void removePlayer(PlayerPtr player);
    const std::set<PlayerPtr>& players() const;
    void clearPlayers();
    virtual NodePtr execResult(int step) = 0;
    virtual NodePtr execResult() = 0;

protected:
    NodeType mType = NodeType::UNKNOWN;
    NodePtr mNext;
    std::weak_ptr<Node> mPre;
    static std::vector<std::string> mTypeNames;
    int mId = 0;
    std::set<PlayerPtr> mPlayers;
};

class NodeA : public Node {
public:
    NodeA();
    ~NodeA();
    NodePtr execResult(int step) override;
    NodePtr execResult() override;
};

class NodeB : public Node {
public:
    NodeB();
    ~NodeB();
    NodePtr execResult(int step) override;
    NodePtr execResult() override;
};

class NodeC : public Node {
public:
    NodeC();
    ~NodeC();
    NodePtr execResult(int step) override;
    NodePtr execResult() override;

private:
    bool mFlag = false;
};

class NodeD : public Node {
public:
    NodeD();
    ~NodeD();
    NodePtr execResult(int step) override;
    NodePtr execResult() override;
};

class NodeE : public Node {
public:
    NodeE();
    ~NodeE();
    NodePtr execResult(int step) override;
    NodePtr execResult() override;
};

} // namespace zwn

#endif
