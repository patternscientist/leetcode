class Solution:
    def isValid(self, s: str) -> bool:
        mp = {')' :'(',
              '}' : '{',
              ']' : '['}
        st = deque()
        for ch in s:
            if not ch in mp:
                st.append(ch)
            elif len(st) == 0 or st.pop() != mp[ch]:
                return False
        return len(st) == 0