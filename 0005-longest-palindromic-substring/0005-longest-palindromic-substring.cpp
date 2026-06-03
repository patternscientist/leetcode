class Solution {
public:
    string longestPalindrome(string s) {
        int n = (int)s.size();
        int bestStart = 0, bestLen = 1;
        auto expand = [&](int l, int r){
            while (l >= 0 && r < n && (s[l] == s[r])){
                l--;
                r++;
            }
            int len = r-l-1;
            if (len > bestLen){
                bestLen   = len;
                bestStart = l+1;
            }
        };

        for (int i=0; i<n; i++){
            expand(i,i);
            expand(i,i+1);
        }
        return s.substr(bestStart,bestLen);
    }
};