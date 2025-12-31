class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        // two pointers
        int i = 0, j = n - 1;

        // invariant: all (alphanumeric) characters strictly outside of [i, j] have been matched and checked
        while (i < j){
            // skip over any non-alphanumeric characters
            while (i < j && !isalnum(s[i])) ++i;
            while (i < j && !isalnum(s[j])) --j;

            if (toupper(s[i]) != toupper(s[j])) // be case-insensitive
                return false; 
            
            ++i;
            --j;           
        }

        return true;
    }
};