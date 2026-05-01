class Solution:
    def addBinary(self, a: str, b: str) -> str:
        carry = 0
        sum_  = 0
        i     = len(a)-1
        j     = len(b)-1
        ans   = ""
        while i >= 0 or j >= 0 or carry:
            sum_ = carry
            if i >= 0:
                sum_ += int(a[i])
                i -= 1
            if j >= 0:
                sum_ += int(b[j])
                j -= 1
            ans += str(sum_ & 1)
            carry = sum_ >> 1
        return ''.join(reversed(ans))