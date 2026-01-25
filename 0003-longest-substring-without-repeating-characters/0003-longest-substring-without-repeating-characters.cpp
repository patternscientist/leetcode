class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> seen(256,-1); // string only has ascii characters
        int start = 0, best = 0;
        char c;
        for (int i=0; i<(int)s.size(); ++i){
            c = s[i];
            if (seen.at(c) != -1)
                start = max(start, seen.at(c)+1);
            best = max(best, i+1-start);
            seen[c] = i;
        }
        return best;
    }
};