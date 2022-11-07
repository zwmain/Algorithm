#include "Utils.hpp"
#include <queue>
#include <unordered_map>

using namespace std;

// 构建小顶堆，小的在队列头部
// 因为是取前k大的，当队列大小到达k时，队头最小，直接移除
// 如果用大顶堆，反而不好移除
struct Cmp {
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs)
    {
        return lhs.second > rhs.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> cntMap;
        for (int i : nums) {
            cntMap[i]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> minQue;
        for (auto& p : cntMap) {
            minQue.push(p);
            if (minQue.size() > k) {
                minQue.pop();
            }
        }
        vector<int> res(minQue.size());
        size_t ind = res.size() - 1;
        while (!minQue.empty()) {
            auto& t = minQue.top();
            res[ind] = t.first;
            --ind;
            minQue.pop();
        }
        return res;
    }
};
