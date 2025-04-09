
from typing import List, Optional
import collections



class Solution:
    def triangularSum(self, nums: List[int]) -> int:
        while len(nums) > 1:
            next = []
            for i in range(len(nums)):
                if i == 0:
                    continue
                next.append((nums[i] + nums[i - 1]) % 10)
            nums = next
        return nums[0]



ss = Solution()
nums = [[1,2,3,4,5], [5]]

for num in nums:
    print(ss.triangularSum(num))





#                1
#               1 1
#              1 2 1
#             1 3 3 1
#            1 4 6 4 1
#          1 5 10 10 5 1
#         1 6 15 20 15 6 1 