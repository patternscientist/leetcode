class Solution {
public:
    string minWindow(string s, string t) {
        int m = (int)s.size(), n = (int)t.size();
        if (m < n) return "";
        vector<int> need(128,0);
        for (char ch : t) need[ch]++;
        int missing = n;
        int l = 0;
        int bestLen = INT_MAX;
        int bestStart = 0;
        for (int r=0; r<m; ++r){
            char cr = s[r];
            if (need[cr] > 0)
                missing--;
            need[cr]--;
            while (missing == 0){
                int winLen = r-l+1;
                if (winLen < bestLen){
                    bestLen = winLen;
                    bestStart = l;
                }
                char cl = s[l];
                need[cl]++;
                if (need[cl] > 0)
                    missing++;
                l++;
            }
        }
        return (bestLen == INT_MAX) ? "" : s.substr(bestStart,bestLen);
    }
};