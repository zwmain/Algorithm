# 0239.滑动窗口最大值

链接：[0239.滑动窗口最大值](https://leetcode.cn/problems/sliding-window-maximum/)

单调队列：队列是单调的，为了维护这个单调性，在向队列尾部添加元素时，如果前面元素和当前元素不满足单调关系，移除前面元素，直到前面元素满足单调性或者队列为空时停止，然后再加入元素。

以单调递减队列为例，前面的元素一定大于等于后面的元素，头部元素是最大的元素。
在向尾部添加元素时，如果当前值大于尾部元素，不满足前面元素大于后面元素的条件，将尾部元素移除，直到队列为空或者前面元素大于当前元素时为止，加入元素。

同样，在移除元素的时候，为了防止还在窗口内的元素被从队列中移除，只有当待移除元素等于队列头部元素时，才移除。
头部永远是最大的数，如果待pop值不等于头部值，要么在头部值后面，要么在当前头部值push时就被挤出了。

```c++
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

```
