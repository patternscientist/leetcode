class Solution:
    def myAtoi(self, s: str) -> int:
        if s == "":
            return 0
        i = 0
        n = len(s)
        while i < n and s[i] == ' ':
            i += 1
        if i == n: return 0
        sign = 1
        if s[i] == '-' or s[i] == '+':
            if s[i] == '-':
                sign *= -1
            i += 1
        MAX = 2**31 - 1
        MIN = -2**31
        ans = 0
        while i < n and s[i].isdigit():
            digit = int(s[i])
            if ans > (MAX - digit) / 10:
                print('dfafdsaf')
                return MAX if sign == 1 else MIN
            ans = ans * 10 + digit
            i += 1
        return sign * ans