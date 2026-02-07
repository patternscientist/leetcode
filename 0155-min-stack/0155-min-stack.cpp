class MinStack {
    struct Node {
        int val;
        Node* next = nullptr;
        
        Node(){};

        Node(int val_){
            val = val_;
        }
    };
public:
    stack<int> st;
    Node* min = nullptr;

    MinStack() {

    }
    
    void push(int val) {
        st.push(val);
        if (!min)
            min = new Node(val);
        else if (val <= min->val){
            Node* tmp = min;
            min = new Node(val);
            min->next = tmp;
        }
    }
    
    void pop() {
        if (min && st.top() == min->val)
            min = min->next;
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min->val;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */