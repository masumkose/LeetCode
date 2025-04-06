
from typing import List
import collections
import math


class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:

        min_k = max(piles)
        left, right = 1, min_k
        
        while left <= right:
            time = 0
            mid = left + ((right - left) // 2)
            for p in piles:
                time += math.ceil(p / mid)
            
            if time <= h:
                min_k = min(mid, min_k)
                right = mid - 1
            else:
                left = mid + 1

        return min_k









ss = Solution()


test_cases= [
                ([3,6,7,11], 8),
                # ([30,11,23,4,20], 5),
                # ([30,11,23,4,20], 6)
            ]


for piles, h in test_cases:
    print(ss.minEatingSpeed(piles, h))
