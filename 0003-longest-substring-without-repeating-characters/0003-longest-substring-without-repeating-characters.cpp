class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), start = 0, best = 0;
        vector<int> seen = vector<int>(256, -1);
        char c;
        for (int i=0; i<n; ++i){
            c = s[i];
            if (seen[c] != -1)
                start = max(start, seen[c]+1);
            best = max(best, i+1-start);
            seen[c] = i;
        }
        return best;
    }
};