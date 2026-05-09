class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int sum_  = 0;
        int i     = (int)a.size()-1;
        int j     = (int)b.size()-1;
        string ans;
        while (i >= 0 || j >= 0 || carry){
            sum_ = carry;
            if (i >= 0)
                sum_ += a[i--]-'0';
            if (j >= 0)
                sum_ += b[j--]-'0';
            ans.push_back('0' + (sum_ & 1));
            carry = sum_ >> 1;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};