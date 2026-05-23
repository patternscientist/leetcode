class Solution:
    def myAtoi(self, s: str) -> int:
        n = len(s)
        i = 0

        # skip leading whitespace
        while i < n and s[i] == ' ':
            i += 1

        # optional sign
        sign = 1
        if i < n and s[i] in {'+','-'}:
            if s[i] == '-':
                sign = -1
            i += 1
        
        # build ans, clamping before overflow
        MAX = int(2**31)-1
        MIN = -int(2**31)
        ans = 0
        while i < n and s[i].isdigit():
            digit = int(s[i])
            if ans > ((MAX - digit)//10):
                return MAX if sign == 1 else MIN
            ans = ans * 10 + digit
            print('new ans:', ans)
            i += 1
        return sign * ans