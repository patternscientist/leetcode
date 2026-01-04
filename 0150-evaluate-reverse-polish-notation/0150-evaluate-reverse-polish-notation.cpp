class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        int n1,n2;
        for (string token : tokens){
            if (token == "+" ||
                token == "-" || 
                token == "*" ||
                token == "/"){
                    n2 = stoi(st.top());
                    st.pop();
                    n1 = stoi(st.top());
                    st.pop();
                    switch (token[0]){
                        case '+': st.push(to_string(n1+n2)); break; 
                        case '-': st.push(to_string(n1-n2)); break;
                        case '*': st.push(to_string(n1*n2)); break;
                        case '/': st.push(to_string(n1/n2)); break;
                    }
                } else st.push(token);
        }
        return stoi(st.top());
    }
};