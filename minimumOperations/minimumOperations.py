
from typing import List, Optional
import collections


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        my_set = set()
        for n in nums:
            if n != 0:
                my_set.add(n)
        return (len(my_set))



ss = Solution()
print(ss.minimumOperations([1,5,0,3,5]))
print(ss.minimumOperations([26, 4, 0 , 0]))




