
from typing import List, Tuple



class Solution(object):
    def removeDuplicates(self, nums):
        if not nums:
            return 0

        reapeat = 0
        index = 1
        for i in range(1, len(nums)):
            if nums[i] == nums[i - 1]:
                reapeat += 1
            else:
                reapeat = 0
            
            if reapeat < 2:
                nums[index] = nums[i]
                index += 1
        return index
        









ss = Solution()

nums = [1,1,1,2,2,3]
k = ss.removeDuplicates(nums)
print (k, nums)

nums = [0,0,1,1,1,1,2,3,3]
k = ss.removeDuplicates(nums)
print (k, nums)