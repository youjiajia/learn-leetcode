class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        _input.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        adjust();
        int x = _output.top();
        _output.pop();
        return x;
    }

    /** Get the front element. */
    int peek() {
        adjust();
        return _output.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return _input.empty() && _output.empty();
    }
private:
    void adjust(){
        if(_output.empty()){
            while(!_input.empty()){
                _output.push(_input.top());
                _input.pop();
            }
        }
    }
    std::stack<int> _input;
    std::stack<int> _output;
};