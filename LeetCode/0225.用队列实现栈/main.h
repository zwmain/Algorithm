#include "Utils.hpp"
#include <queue>

using namespace std;

class MyStack {
public:
    MyStack()
    {
    }

    void push(int x)
    {
        _q.push(x);
    }

    int pop()
    {
        for (size_t i = 0; i < _q.size() - 1; ++i) {
            int val = _q.front();
            _q.pop();
            _q.push(val);
        }
        int val = _q.front();
        _q.pop();
        return val;
    }

    int top()
    {
        int val = pop();
        _q.push(val);
        return val;
    }

    bool empty()
    {
        return _q.empty();
    }

private:
    queue<int> _q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
