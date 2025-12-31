class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        // two pointers
        int i = 0, j = n - 1;

        // invariant: all character strictly outside of [i, j] have been matched and checked;
        // i.e., s[0..i-1] mirrors s[j+1..n-1]
        while (i < j){
            // skip over any non-alphanumeric characters
            while (i < n-1  && !isalnum(s[i])) ++i;
            while (j > 0    && !isalnum(s[j])) --j;

            if (i < j && toupper(s[i]) != toupper(s[j])) // check if i is still less than j, and be case-insensitive
                return false; 
            
            ++i;
            --j;           
        }

        return true;
    }
};