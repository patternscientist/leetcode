class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(),wordDict.end());
        int maxLen = 0;
        for (const string& word : wordDict)
            maxLen = max(maxLen, (int)word.size());
        int n = (int)s.size(); // length of string
        vector<bool> dp(n+1,false);
        dp[0] = true;
        for (int i=1; i<=n; i++){
            for (int len=1; len<=min(i,maxLen); len++){
                int j = i-len;
                dp[i] = dp[j] && wordSet.contains(s.substr(j,len));
                if (dp[i])
                    break;
            }
        }
        return dp[n];
    }
};