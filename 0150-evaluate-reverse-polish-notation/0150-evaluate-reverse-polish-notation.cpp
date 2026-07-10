class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string,function<int(int,int)>> ops =  {{"+", [](int x, int y){ return x+y;}},
                                                             {"-", [](int x, int y){ return x-y;}},
                                                             {"*", [](int x, int y){ return x*y;}},
                                                             {"/", [](int x, int y){ return x/y;}}};
        stack<int> st;
        for (const string& token : tokens){
            if (ops.contains(token)){
                int y = st.top();
                st.pop();
                int x = st.top();
                st.pop();
                st.push(ops[token](x,y));
            } else 
                st.push(stoi(token));
        }
        return st.top();
    }
};