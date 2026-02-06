class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 0;
        int seen[58];
        for (char c : s)
            ++seen[c-'A'];
        bool hasCenterPoint = false;
        for (int n : seen){
            if (n % 2 == 1){
                hasCenterPoint = true; // longest permutation must be odd length with a center point
                ans += n-1;
            } else 
                ans += n;
        }
        if (hasCenterPoint) ans += 1;
        return ans;
    }
};