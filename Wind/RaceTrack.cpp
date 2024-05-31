// utf8文件头
#include "RaceTrack.h"
#include "Dice.h"

#include <iostream>
#include <map>

namespace zwn {

RaceTrack::RaceTrack(const std::string& nodeCfg, const std::vector<std::string>& playerCfg)
{
    NodePtr pre;
    int id = 0;
    for (char c : nodeCfg) {
        NodePtr node = Node::create(c);
        if (!node) {
            continue;
        }
        if (!mHead) {
            mHead = node;
        }
        ++id;
        node->setId(id);
        node->setPrev(pre);
        if (pre) {
            pre->setNext(node);
        }
        pre = node;
    }
    mEnd = pre;

    for (auto& name : playerCfg) {
        mPlayers.push_back(std::make_shared<Player>(name));
    }
}

RaceTrack::~RaceTrack()
{
}

void RaceTrack::logTrack()
{
    NodePtr node = mHead;
    while (node) {
        std::cout << node->typeName();
        NodePtr next = node->next();
        if (next) {
            std::cout << " -> ";
        }
        node = next;
    }
    std::cout << std::endl;
}

void RaceTrack::startRace()
{
    sortPlayers();
    for (auto& player : mPlayers) {
        player->setCurrentNode(mHead);
        mHead->addPlayer(player);
    }
    logInitInfo();

    int index = 1;
    while (!isAllFinish()) {
        std::cout << "第" << index << "轮：" << std::endl;
        for (auto& player : mPlayers) {
            if (player->isFinish()) {
                std::cout << player->name() << "：已经到达终点" << std::endl;
                continue;
            }
            int val = Dice::instance()->value();
            std::cout << player->name() << "：投掷选择" << val << "，";
            int res = Dice::instance()->value(val);
            std::cout << "结果" << res << "，";
            NodePtr curNode = player->currentNode();
            curNode->removePlayer(player);
            curNode = curNode->execResult(res);
            std::cout << "前进至节点" << curNode->id();
            NodePtr tempNode = curNode->execResult();
            while (curNode != tempNode) {
                curNode = tempNode;
                std::cout << "，回退至节点" << curNode->id();
                tempNode = curNode->execResult();
            }
            if (curNode != mEnd && curNode != mHead) {
                auto& otherPlayers = curNode->players();
                for (auto& otherPlayer : otherPlayers) {
                    otherPlayer->setCurrentNode(mHead);
                    mHead->addPlayer(otherPlayer);
                    std::cout << "，将" << otherPlayer->name() << "踢回到节点" << mHead->id();
                }
                curNode->clearPlayers();
            }
            curNode->addPlayer(player);
            player->setCurrentNode(curNode);
            if (curNode == mEnd) {
                mScores[player] = index;
                std::cout << "，到达终点";
            }
            std::cout << std::endl;
        }
        ++index;
    }

    std::sort(mPlayers.begin(), mPlayers.end(),
        [&](PlayerPtr a, PlayerPtr b) {
            return mScores[a] < mScores[b];
        });
    std::cout << "获胜选手：" << mPlayers[0]->name() << std::endl;

    for (auto& player : mPlayers) {
        std::cout << player->name() << "投掷次数：" << mScores[player] << std::endl;
    }
}

void RaceTrack::sortPlayers()
{
    std::map<PlayerPtr, int> scores;
    for (auto& player : mPlayers) {
        int val = Dice::instance()->value();
        scores[player] = val;
    }
    std::sort(mPlayers.begin(), mPlayers.end(),
        [&scores](PlayerPtr a, PlayerPtr b) {
            return scores[a] > scores[b];
        });
}

void RaceTrack::logInitInfo()
{
    std::cout << "0: ";
    for (auto& player : mPlayers) {
        std::cout << player->name() << "在节点" << player->currentNode()->id() << "，";
    }
    std::cout << "投掷顺序（";
    for (size_t i = 0; i < mPlayers.size(); ++i) {
        std::cout << mPlayers[i]->name();
        if (i < mPlayers.size() - 1) {
            std::cout << "，";
        }
    }
    std::cout << "）" << std::endl;
}

bool RaceTrack::isAllFinish()
{
    for (auto& player : mPlayers) {
        if (!player->isFinish()) {
            return false;
        }
    }
    return true;
}

} // namespace zwn
