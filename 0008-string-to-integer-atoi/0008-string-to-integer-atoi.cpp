class Solution {
public:
    int myAtoi(string s) {
        int n = (int)s.size();
        int i = 0;
        long long ans = 0;
        bool positive = true;
        while (s[i] == ' ') i++;
        if (s[i] == '-'){
            positive = false;
            i++;
        } else if (s[i] == '+')
            i++;
        while (s[i] == '0') i++;
        while (i < n && isdigit(s[i])){
            if (ans > INT_MAX/10){
                ans = positive ? INT_MAX : INT_MIN;
                return ans;
            }
            ans *= 10;
            ans += (long long)s[i]-'0';
            i++;
        }
        if (!positive){
            ans *= -1;
            ans = max(ans,(long long)INT_MIN);
        } else
            ans = min(ans,(long long)INT_MAX);
        return ans;
    }
};