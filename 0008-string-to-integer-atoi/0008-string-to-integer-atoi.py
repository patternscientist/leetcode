class Solution:
    def myAtoi(self, s: str) -> int:
        n    = len(s)
        i    = 0
        sign = 1
        while i < n and s[i] == ' ':
            i += 1
        if i < n and s[i] in {'+','-'}:
            if s[i] == '-':
                sign *= -1
            i += 1
        ans = 0
        MAX = int(2**31)
        while i < n and s[i].isdigit():
            if MAX < ans//10:
                ans = MAX
                break
            ans *= 10
            ans += int(s[i])
            i += 1
        ans = min(ans,MAX)
        ans *= sign
        if sign == -1 or not ans == MAX:
            return ans
        else:
            return MAX-1
        

        