class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int INF = amount+1;
        vector<int> dp(amount+1,INF);
        dp[0] = 0;
        for (int k=1; k<=amount; ++k){
            for (int denom : coins){
                if (k - denom >= 0)
                    dp[k] = min(dp[k],dp[k-denom]+1);
            }
        }
        return dp[amount] == INF ? -1 : dp[amount];
    }
};