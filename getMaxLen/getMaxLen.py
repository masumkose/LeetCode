
from typing import List, Optional
import collections



class Solution:
    def getMaxLen(self, nums: List[int]) -> int:
        ans, pos, neg = 0, 0, 0
        for n in nums:
            if n < 0:
                pos, neg = 1 + neg if neg else 0, 1 + pos
            elif n > 0:
                neg = 1 + neg if neg else 0
                pos += 1
            else:
                pos = neg = 0
            ans = max(ans, pos)
        return ans



ss = Solution()

test_nums = [
    [1,-2,-3,4],
    [0,1,-2,-3,-4],
    [-1,-2,-3,0,1],
    [-1,2],
]

for nums in test_nums:
    print(ss.getMaxLen(nums))



