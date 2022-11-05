# 0232.用栈实现队列

[0232.用栈实现队列](https://leetcode.cn/problems/implement-queue-using-stacks/)

思路：栈是先进后出，队列是先进先出，相反。使用两个栈，把倒过来的顺序再倒一次，以达到正序的目的。
设置一个输入栈，只负责接受push进来的数据。设置一个输出栈，如果是空的，就把输入栈的元素**全部**，转入转入输出栈。
输出栈，在**清空**之前，里面的元素都是先进先出有序的，不能在还没清空的时候，从输入栈转元素进来。

```c++
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

```
