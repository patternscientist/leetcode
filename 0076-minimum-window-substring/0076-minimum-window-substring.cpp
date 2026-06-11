class Solution {
public:
    string minWindow(string s, string t) {
        int m = (int)s.size();
        int n = (int)t.size();
        if (m < n)
            return "";
        int need[58];
        for (char ch : t)
            need[ch-'A']++;
        int missing = n;
        int bestStart = 0;
        int bestLen = INT_MAX;
        int l = 0;
        for (int r=0; r<m; r++){
            char cr = s[r];
            if (need[cr-'A'] > 0)
                missing--;
            need[cr-'A']--;
            while (missing == 0){
                int len = r-l+1;
                if (len < bestLen){
                    bestLen = len;
                    bestStart = l;
                }
                int cl = s[l];
                need[cl-'A']++;
                if (need[cl-'A'] > 0)
                    missing++;
                l++;
            }
        }
        return (bestLen == INT_MAX) ? "" : s.substr(bestStart,bestLen);
    }
};