class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(),
                                      wordDict.end());
        int maxLen = 0;
        for (const string& w : wordDict)
            maxLen = max(maxLen, (int)w.size());
        int sz = (int)s.size();
        vector<bool> dp(sz,false);
        dp[0] = true;
        for (int i=0; i<=sz; i++){
            for (int len=1; len<=min(i,maxLen); len++){
                int j = i-len;
                if (dp[j] && wordSet.contains(s.substr(j,len))){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[sz];
    }
};