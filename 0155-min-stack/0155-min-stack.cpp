class MinStack {
    struct Node{
        int val;
        int count  = 0;
        Node* next = nullptr;

        Node(){++count;};
        Node(int val_){
            val = val_;
            ++count;
        };
    };

public:
    stack<int> st;
    Node* min = nullptr;

    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if (!min){
            min = new Node(val);
        } else if (val == min->val){
            ++min->count;
        } else if (val < min->val){
            Node* tmp = min;
            min = new Node(val);
            min->next = tmp;
        }
    }
    
    void pop() {
        if (min->val == st.top() && --min->count == 0)
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