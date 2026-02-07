class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int start = 0, best = 0;
        vector<int> seen(256,-1);
        for (int i=0; i<n; ++i){
            char ch = s[i];
            if (seen[ch] != -1)
                start = max(start, seen[ch]+1);
            best = max(best, i-start+1);
            seen[ch] = i;
        }
        return best;
    }
};