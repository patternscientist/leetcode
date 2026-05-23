class Solution {
public:
    int myAtoi(string s) {
        int n = (int)s.size();
        int i = 0;
        // skip whitespace
        while (i < n && s[i] == ' ') i++;
        // account for sign
        int sign = 1;
        if (i < n && (s[i] == '-' || s[i] == '+')){
            if (s[i] == '-')
                sign = -1;
            i++;
        }
        // process digits, clamping before overflow
        int ans = 0;
        while (i < n && isdigit(s[i])){
            int digit = s[i]-'0';
            if (ans > (INT_MAX - digit) / 10)
                return sign == 1 ? INT_MAX : INT_MIN;
            ans = ans * 10 + digit;
            i += 1;
        }
        return sign * ans;
    }
};