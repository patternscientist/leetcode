class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0) return 0;
        int start = 0, best = 1;
        unordered_set<char> seen;
        unordered_map<char,int> mp{{s[0],0}};
        bool update;
        for (int i=1; i<n; ++i){
            unordered_map<char,int> mpNew;
            update = false;
            if (auto it=mp.find(s[i]); it!=mp.end()){
                update = true;
                start = mp[s[i]]+1;
                for (auto const& [c,j] : mp){
                    if (j >= start) mpNew.insert({c,j});
                }
            }
            if (update) mp = mpNew;
            best = max(best, i+1-start);
            mp[s[i]] = i;
        }
        return best;
    }
};