
from typing import List
import collections


class Solution:
    def findMin(self, nums: List[int]) -> int:

        res = nums[0]
        l, r = 0, len(nums) - 1

        while l <= r:
            if nums[l] < nums[r]:
                res = min(nums[l], res)
            
            m = l + ((r - l) // 2)
            res = min(res, nums[m])
            if nums[m] >= nums[l]:
                l = m + 1
            else:
                r = m - 1
        
        return res







ss = Solution()


testcase =  [
                [3,4,5,1,2], 
                [4,5,6,7,0,1,2],
                [11,13,15,17],
            ]


for test in testcase:
    print(ss.findMin(test))



# [3, 4, 5, 6, 1, 2, 3] 

# l = 0, r = 6, mid = 3