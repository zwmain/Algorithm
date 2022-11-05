# Day10.用队列实现栈、用栈实现队列

## 0232.用栈实现队列

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

## 0225.用队列实现栈

链接：[0225.用队列实现栈](https://leetcode.cn/problems/implement-stack-using-queues/)

思路：和用栈实现队列那种“负负得正”不同，队列正正也不能得负。但是我们需要明确一点，我们每次按序添加，
但是需要的永远是最后一个数。每次取数之前，把除最后一个数以外的其他所有数都从队列中取出再放入队列，
这样最后一个数就到最前面了。此时要么直接取出，要么取出后再放回队列后面。

```c++
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

```

