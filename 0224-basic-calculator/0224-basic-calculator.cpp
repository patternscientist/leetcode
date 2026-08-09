class Solution {
public:
    int parse(const string& s, int& i){
        int n = (int)s.size();
        long long ans = 0;
        int sign = 1;
        while (i < n){
            if (s[i] == ' ')
                i++;
            else if (s[i] == '+'){
                sign = 1;
                i++;
            } else if (s[i] == '-'){
                sign = -1;
                i++;
            } else if (isdigit(s[i])){
                long long num = 0;
                while (i < n && isdigit(s[i])){
                    num = num * 10 + (s[i]-'0');
                    i++;
                }
                ans += sign * num;
                sign = 1;
            } else if (s[i] == '('){
                i++;
                int value = parse(s,i);
                ans += sign * value;
                sign = 1;
            } else { // s[i] == ')'
                i++;
                return ans;
            }
        }
        return ans;
    }
    int calculate(string s) {
        int i = 0;
        return parse(s,i);
    }
};