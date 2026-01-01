class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        // two pointers
        int i = 0, j = n - 1;

        // invariant: all (alphanumeric) characters strictly outside of [i, j] have been checked and matched
        while (i < j){
            // skip over any non-alphanumeric characters
            while (i < j && !isalnum((unsigned char) s[i])) ++i; // char is signed on some platforms so cast to unsigned for safety
            while (i < j && !isalnum((unsigned char) s[j])) --j;

            if (tolower((unsigned char) s[i]) != tolower((unsigned char) s[j])) // be case-insensitive
                return false; 
            
            ++i; --j;           
        }

        return true;
    }
};
