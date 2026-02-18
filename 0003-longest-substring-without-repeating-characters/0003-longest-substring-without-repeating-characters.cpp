class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int best  = 0;
        int start = 0;
        int n = s.size();
        vector<int> seen(256,-1);
        for (int i=0; i<n; ++i){
            char ch = s[i];
            if (seen[ch] != -1)
                start = max(start,seen[ch]+1);
            best = max(best,i-start+1);
            seen[ch] = i;
        }
        return best;
    }
};