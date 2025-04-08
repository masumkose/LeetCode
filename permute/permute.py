
from typing import List, Optional
import collections



class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []

        def dfs(i, curr, pick):
            if len(curr) == len(nums):
                res.append(curr.copy())
                return
            
            for m in range(len(nums)):
                if not pick[m]:
                    curr.append(nums[m])
                    pick[m] = True
                    dfs(m + 1, curr, pick)
                    curr.pop()
                    pick[m] = False
    
        dfs(0, [], [False] * len(nums))

        return res




nums = [1,2,3]


ss = Solution()

print(ss.permute(nums))




