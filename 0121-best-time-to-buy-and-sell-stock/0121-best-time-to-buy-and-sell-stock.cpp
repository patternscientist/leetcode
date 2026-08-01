class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int best = 0;
        int minPrice = prices[0];
        for (int i=1; i<(int)prices.size(); i++){
            minPrice = min(minPrice,prices[i]);
            best = max(best,prices[i]-minPrice);
        }
        return best;
    }
};