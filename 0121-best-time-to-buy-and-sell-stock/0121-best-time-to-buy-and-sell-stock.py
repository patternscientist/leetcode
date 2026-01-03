class Solution(object):
    def maxProfit(self, prices):
        minPrice  = None
        maxProfit = 0
        for price in prices:
            if minPrice is None: minPrice = price
            maxProfit = max(maxProfit, max(price - minPrice,0))
            minPrice  = min(minPrice, price)
        return maxProfit
        