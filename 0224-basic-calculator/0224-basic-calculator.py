class Solution:
    def calculate(self, s: str) -> int:
        i = 0
        n = len(s)
        def parse(s,n,i):
            sign = 1
            ans  = 0
            while i < n:
                if s[i] == ' ':
                    i += 1
                elif s[i] == '+':
                    sign = 1
                    i += 1
                elif s[i] == '-':
                    sign = -1
                    i += 1
                elif s[i].isdigit():
                    num = 0
                    while i < n and s[i].isdigit():
                        num = num * 10 + int(s[i])
                        i += 1
                    ans += sign * num
                    sign = 1
                elif s[i] == '(':
                    i += 1
                    value,i = parse(s,n,i)
                    ans += sign * value
                    sign = 1
                elif s[i] == ')':
                    i += 1
                    return (ans,i)
            return (ans,i)
        ans,_ = parse(s,n,i)
        return ans