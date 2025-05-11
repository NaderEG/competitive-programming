class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxProfit = 0

        if len(prices) <= 1:
            return maxProfit
        
        l = 0
        r = 1

        while r <= len(prices)-1:
            if prices[r] - prices[l] >= 0:
                if prices[r] - prices[l] > maxProfit:
                    maxProfit = prices[r] - prices[l]
                r = r+1
            else:
                l = r
        return maxProfit