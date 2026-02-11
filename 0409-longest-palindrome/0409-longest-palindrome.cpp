class Solution {
public:
    int longestPalindrome(string s) {
        int seen[256];
        int ans = 0;
        for (char ch : s)
            seen[ch]++;
        bool hasCenter = false;
        for (int freq : seen){
            ans += floor(freq / 2) * 2;
            if (!hasCenter && freq % 2 == 1)
                hasCenter = true;
        }
        if (hasCenter) ans++;
        return ans;
    }
};