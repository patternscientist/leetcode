class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_set<string> ops = {"+","-","*","/"};
        stack<int> st;
        for (string token : tokens){
            if (ops.count(token)){
                int n2 = st.top(); st.pop();
                int n1 = st.top(); st.pop();
                if (token == "+")
                    st.push(n1+n2);
                else if (token == "-") 
                    st.push(n1-n2);
                else if (token == "*")
                    st.push(n1*n2);
                else 
                    st.push(n1/n2);
            } else 
                st.push(stoi(token));
        }
        return st.top();
    }
};