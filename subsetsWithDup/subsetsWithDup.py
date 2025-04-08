
from typing import List, Optional
import collections


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()

        def dfs(i, cur):
            if (i >= len(nums)):
                res.append(cur.copy())
                return
            cur.append(nums[i])
            dfs(i + 1, cur)
            cur.pop()
            while i + 1 < len(nums) and nums[i] == nums[i + 1]:
                i += 1
            dfs(i + 1, cur)
        dfs(0, [])
        return res



nums = [1,2,2]

ss = Solution()

print(ss.subsetsWithDup(nums))




