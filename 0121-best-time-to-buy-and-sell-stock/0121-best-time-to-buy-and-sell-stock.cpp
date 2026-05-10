class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int best    = 0;
        int bottom  = INT_MAX;
        for (int price : prices){
            bottom = min(bottom, price);
            best   = max(best, price-bottom);
        }
        return best;
    }
};