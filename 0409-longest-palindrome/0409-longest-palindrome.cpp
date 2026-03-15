class Solution {
public:
    int longestPalindrome(string s) {
        int seen[128];
        for (char ch : s)
            seen[ch]++;
        bool hasCenter = false;
        int ans = 0;
        for (int freq : seen){
            ans += (freq / 2) * 2;
            if (freq % 2 != 0 && !hasCenter)
                hasCenter = true;
        }
        return hasCenter ? ans+1 : ans;
    }
};