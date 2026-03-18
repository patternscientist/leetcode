class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size(), n = b.size();
        string padding;
        for (int i=0; i<abs(m-n); ++i)
            padding.push_back('0');
        if (m > n)
            b = padding + b;
        else
            a = padding + a;
        int carry  = 0;
        int curSum = 0;
        stack<char> ansStack;
        string ans;
        for (int i=max(m,n)-1; i>=0; --i){
            curSum = (a[i]-'0') + (b[i]-'0');
            ansStack.push('0' + ((curSum + carry) % 2));
            carry  = curSum + carry > 1 ? 1 : 0;
            if (i == 0 && carry == 1)
                ansStack.push('1');
        }
        while (!ansStack.empty()){
            ans.push_back(ansStack.top()); 
            ansStack.pop();
        }
        return ans;

    }
};