#include "Utils.hpp"
#include <deque>

using namespace std;

// 单调递减队列
class MonoDecQueue {
public:
    void push(int val)
    {
        // 如果待加入值前面，即队列尾部，有比当前值小的，移除
        // 保证队列在前面的都是大的，单调递减
        while (!_dq.empty() && val > _dq.back()) {
            _dq.pop_back();
        }
        _dq.push_back(val);
    }
    void pop(int val)
    {
        // 只有当头部值等于待pop值时，才pop
        // 头部永远是最大的数，如果待pop值不等于头部值
        // 要么在头部值后面，要么在push时就被挤出了
        if (!_dq.empty() && _dq.front() == val) {
            _dq.pop_front();
        }
    }
    int front()
    {
        return _dq.front();
    }

private:
    deque<int> _dq;
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        vector<int> res;
        if (nums.size() < k) {
            return res;
        }
        MonoDecQueue mdq;
        for (size_t i = 0; i < k; ++i) {
            mdq.push(nums[i]);
        }
        int curMax = mdq.front();
        res.push_back(curMax);
        for (size_t i = 1; i <= nums.size() - k; ++i) {
            // 前一个元素从窗口移除
            mdq.pop(nums[i - 1]);
            // 新的元素进入窗口
            mdq.push(nums[i + k - 1]);
            curMax = mdq.front();
            res.push_back(curMax);
        }
        return res;
    }
};
