
from typing import List, Optional
import collections


class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []


        def dfs(i, subset):
            if i >= len(nums):
                res.append(subset.copy())
                return

            subset.append(nums[i])
            dfs(i + 1, subset)
            subset.pop()
            dfs(i + 1, subset)

        dfs(0, [])
        return res



ss = Solution()

tests = [1,2,3]

print(ss.subsets(tests))





