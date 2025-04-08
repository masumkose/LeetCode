
from typing import List
import collections




class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxP = 0
        l, r = 0, 1 # left-buy right-sell

        while r < len(prices):

            if prices[l] < prices[r]:
                profit = prices[r] - prices[l]
                maxP = max(maxP, profit)
            else:
                l = r
            r += 1
        return maxP







test = [[7,1,5,3,6,4], [7,6,4,3,1]]


ss = Solution()

for prices in test:
    print(ss.maxProfit(prices))

