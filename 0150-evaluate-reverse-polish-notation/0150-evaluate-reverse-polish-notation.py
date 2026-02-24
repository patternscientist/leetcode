class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        sign = lambda x: 1 if x == 0 else x // abs(x)
        ops = {"+" : lambda x,y: x+y,
               "-" : lambda x,y: x-y,
               "*" : lambda x,y: x*y,
               "/" : lambda x,y: (sign(x) * sign(y)) * (abs(x) // abs(y))}
        st = deque()
        for token in tokens:
            if token in ops:
                n2 = st.pop()
                n1 = st.pop()
                st.append(ops[token](n1,n2))
            else:
                st.append(int(token))
        return st[-1]