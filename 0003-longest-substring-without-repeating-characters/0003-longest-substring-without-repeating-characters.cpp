class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int start = 0;
        int best  = 0;
        vector<int> seen(256,-1); // stores indices of seen chars
        char c;
        for (int i=0; i<n; ++i){
            c = s[i];
            if (seen[c] != -1)
                start = max(start, seen[c]+1);
            best = max(best, i-start+1);
            seen[c] = i;
        }
        return best;
    }
};