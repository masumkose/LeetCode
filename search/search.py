
from typing import List
import collections





class Solution:
    def search(self, nums: List[int], target: int) -> int:


        l, r = 0, len(nums) - 1

        while l <= r:
            m = (r + l) // 2
            if (nums[m] == target): return m

            if nums[l] <= nums[m]:
                if target > nums[m] or target < nums[l]:
                    l = m + 1
                else:
                    r = m - 1
            else:
                if target < nums[m] or target > nums[r]:
                    r = m - 1
                else:
                    l = m + 1

        return -1


ss = Solution()

test_cases = [([4,5,6,7,0,1,2], 0), ([4,5,6,7,0,1,2], 3), ([1], 0), ([3,5,1], 3), ([4,5,6,7,0,1,2], 5)]


for nums, target in test_cases:
    print(ss.search(nums, target))


 




