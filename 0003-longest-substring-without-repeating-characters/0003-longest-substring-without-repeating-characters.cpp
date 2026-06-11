class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> seen(256,-1);
        int start = 0;
        int best  = 0;
        for (int i=0; i<(int)s.size(); i++){
            char ch = s[i];
            if (seen[ch] != -1)
                start = max(start,seen[ch]+1);
            best = max(best,i-start+1);
            seen[ch] = i;
        }
        return best;
    }
};