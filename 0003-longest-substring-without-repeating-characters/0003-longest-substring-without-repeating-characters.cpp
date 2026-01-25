class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = (int)s.size(), start = 0, best = 0;
        unordered_map<char,int> mp;
        char c;
        for (int i=0; i<n; ++i){
            c = s[i];
            if (auto it=mp.find(c); it!=mp.end())
                start = max(start, it->second + 1);
            best = max(best,i+1-start);
            mp[c] = i;
        }
        return best;
    }
};