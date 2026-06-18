class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = (int)s.size();
        vector<int>seen(256,-1);
        int start = 0;
        int best  = 0;
        for (int i=0; i<n; i++){
            char c = s[i];
            if (seen[c] != -1)
                start = max(start,seen[c]+1);
            best = max(best,i-start+1);
            seen[c] = i;
        }
        return best;
    }
};