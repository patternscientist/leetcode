class MyQueue {
public:
    stack<int> front;
    stack<int> back;

    MyQueue() {
        
    }

    void pour(){
        if (!front.empty())
            return;
        while (!back.empty()){
            front.push(back.top());
            back.pop();
        }
    }
    
    void push(int x) {
        back.push(x);
    }
    
    int pop() {
        pour();
        int x = front.top();
        front.pop();
        return x;
    }
    
    int peek() {
        pour();
        return front.top();
    }
    
    bool empty() {
        return front.empty() && back.empty();
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