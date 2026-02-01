class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0], best = 0;
        for (int i=1; i<(int)prices.size(); ++i){
            minPrice = min(minPrice, prices[i]);
            best     = max(best, prices[i] - minPrice);
        }
        return best;
    }
};