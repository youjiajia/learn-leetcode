#include <stdio.h>
#include <queue>

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        std::queue<int> temp;
        temp.push(x);
        while(!_data.empty()){
            temp.push(_data.front());
            _data.pop();
        }
        _data = temp;
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x = _data.front();
        _data.pop();
        return x;
    }

    /** Get the top element. */
    int top() {
        return _data.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return _data.empty();
    }
private:
    std::queue<int> _data;
};