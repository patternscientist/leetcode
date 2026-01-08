class Solution:
    def isValid(self, s: str) -> bool:
        mp = {')':'(', ']':'[', '}':'{'}
        st = deque()
        for c in s:
            if c == '(' or c == '[' or c == '{':
                st.append(c)
            elif len(st) == 0 or mp[c] != st.pop():
                return False
        return len(st) == 0