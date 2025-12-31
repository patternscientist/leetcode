class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX; 
        int profit;
        int ans = 0;

        // Invariant: after each iteration, minPrice is the smallest price seen so far,
        // and ans is the maximum profit achievable using a buy day before a sell day 
        // within the prices seen so far.
        for (int p : prices){
            profit = max(p - minPrice, 0); // sell today after buying at the bottom
            ans = max(ans, profit);  // update best profit
            minPrice = min(minPrice, p); // update best buy price
        }
        return ans;
    }
};