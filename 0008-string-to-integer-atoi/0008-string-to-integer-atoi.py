class Solution:
    def myAtoi(self, s: str) -> int:
        n = len(s)
        i = 0
        # skip whitespace
        while i < n and s[i] == ' ':
            i += 1
        # account for sign
        sign = 1
        if i < n and (s[i] == '+' or s[i] == '-'):
            if s[i] == '-':
                sign = -1
            i += 1
        # build answer, clamping before overflow
        MAX = int(2**31)-1
        MIN = -int(2**31)
        ans = 0
        while i < n and s[i].isdigit():
            digit = int(s[i])
            if ans > (MAX - digit) // 10:
                return MAX if sign == 1 else MIN
            ans = ans * 10 + digit
            i += 1
        return sign * ans