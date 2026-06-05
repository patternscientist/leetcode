class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(),
                                      wordDict.end());
        int n = (int)s.size();
        int maxLen = 0;
        for (const string& w : wordDict)
            maxLen = max(maxLen,(int)w.size());
        vector<bool> dp(n+1,false);
        dp[0] = true;
        for (int i=1; i<=n; i++){
            for (int len=1; len<=min(i,maxLen); len++){
                int j=i-len;
                if (dp[j] && wordSet.contains(s.substr(j,len))){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};