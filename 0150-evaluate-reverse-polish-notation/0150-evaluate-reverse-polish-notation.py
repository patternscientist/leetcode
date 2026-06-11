class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        ops = {"+" : lambda x,y: x+y,
               "-" : lambda x,y: x-y,
               "*" : lambda x,y: x*y,
               "/" : lambda x,y: floor(x/y) if x*y > 0 else ceil(x/y)}
        st = deque()
        for token in tokens:
            if token in ops:
                n2 = st.pop()
                n1 = st.pop()
                st.append(ops[token](n1,n2))
            else:
                st.append(int(token))
        return st[0]