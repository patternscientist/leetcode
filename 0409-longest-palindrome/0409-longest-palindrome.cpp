class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 0;
        int seen[256];
        for (char c : s)
            ++seen[c];
        bool single = false;
        for (int n : seen){
            if (n % 2 == 1){
                single = true;
                ans += n-1;
            } else 
                ans += n;
        }
        if (single) ans += 1;
        return ans;
    }
};