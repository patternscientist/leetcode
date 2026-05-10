class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int best    = 0;
        int bottom  = prices[0];
        for (int price : prices){
            bottom = min(bottom, price);
            best   = max(best, price-bottom);
        }
        return best;
    }
};