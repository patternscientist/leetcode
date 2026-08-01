class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int best = 0;
        int start = 0;
        vector<int> seen(256,-1);
        for (int i=0; i<(int)s.size(); i++){
            char ch = s[i];
            if (seen[ch] != -1)
                start = max(start,seen[ch]+1);
            int len = i-start+1;
            best = max(best,len);
            seen[ch] = i;
        }
        return best;
    }
};