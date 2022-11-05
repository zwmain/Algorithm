# 0225.用队列实现栈

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
