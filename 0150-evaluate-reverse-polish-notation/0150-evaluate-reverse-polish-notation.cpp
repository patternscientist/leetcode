class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n1,n2;
        stack<int> s;
        for (string token : tokens){
            if (token == "+" ||
                token == "-" ||
                token == "*" ||
                token == "/"){
                n2 = s.top(); s.pop();
                n1 = s.top(); s.pop();
                if (token == "+")
                    s.push(n1+n2);
                else if (token == "-")
                    s.push(n1-n2);
                else if (token == "*")
                    s.push(n1*n2);
                else 
                    s.push(n1/n2);
            } else 
                s.push(stoi(token));
        }
        return s.top();
    }
};