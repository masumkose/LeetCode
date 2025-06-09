
from typing import List, Optional
import collections





class Solution:
    def goodDaysToRobBank(self, securtiy: List[int], time: int) -> List[int]:
        size = len(securtiy)
        increasing = [0] * size
        decreasing = [0] * size

        for i in range(1, size):
            if securtiy[i] <= securtiy[i - 1]:
                increasing[i] = increasing[i - 1] + 1

        for i in range(size -2, -1, -1):
            if securtiy[i] <= securtiy[i + 1]:
                decreasing[i] = decreasing[i + 1] + 1

        res = [i for i in range(size) if time <= min(increasing[i], decreasing[i])]
            
        return res



ss = Solution()


""" 
[5,3,3,3,5,6,2] = time = 2


"""
print(ss.goodDaysToRobBank([5,3,3,3,5,6,2], 2))

