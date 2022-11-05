#include "Utils.hpp"
#include <stack>

using namespace std;

class MyQueue {
public:
    MyQueue()
    {
    }

    void push(int x)
    {
        _iStk.push(x);
    }

    int pop()
    {
        moveValToOutStk();
        int val = _oStk.top();
        _oStk.pop();
        return val;
    }

    int peek()
    {
        moveValToOutStk();
        return _oStk.top();
    }

    bool empty()
    {
        return _iStk.empty() && _oStk.empty();
    }

private:
    stack<int> _iStk;
    stack<int> _oStk;

    void moveValToOutStk()
    {
        if (!_oStk.empty()) {
            return;
        }
        while (!_iStk.empty()) {
            int val = _iStk.top();
            _iStk.pop();
            _oStk.push(val);
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
