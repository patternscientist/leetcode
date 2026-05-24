class MyQueue {
public:
    stack<int> in;
    stack<int> out;

    MyQueue() {
        
    }

    void pour(){
        if (!out.empty()) 
            return;
        while (!in.empty()){
            out.push(in.top());
            in.pop();
        }
    }
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        pour();
        int x = out.top();
        out.pop();
        return x;
    }
    
    int peek() {
        pour();
        return out.top();
    }
    
    bool empty() {
        return in.empty() && out.empty();
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