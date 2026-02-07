class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int INF = amount + 1;
        vector<int> dp(amount+1,INF);
        dp[0] = 0;
        for (int n=1; n<=amount; ++n){
            for (int denom : coins){
                if (denom <= n) 
                    dp[n] = min(dp[n],dp[n-denom]+1);
            }
        }
        return dp[amount] == INF ? -1 : dp[amount];
    }
};