from typing import List
import collections

class Solution:

    def search(self, nums: List[int], target: int) -> int:
        
        l,r = 0, len(nums) - 1

        while l <= r:

            m = l + ((r - l) // 2)
            if nums[m] == target:
                return m
            
            if nums[m] < target:
                r = m - 1
            else:
                l = m + 1


        return -1




    def search_easy(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums) - 1

        while left <= right:
            mid = left + ((left - right) // 2)
            if target == nums[mid]:
                return mid
            elif target < nums[mid]:
                right = mid - 1
            else:
                left = mid + 1
            
        return -1


    def search_recursion_method(self, nums: List[int], target: int) -> int:
        return self.recursion(nums, target, 0, len(nums) - 1)

    def recursion(self, nums: List[int], target: int, start: int, end: int) -> bool:
        if start > end:
            return -1

        middle = start + ((start - end) // 2)
        if nums[middle] == target:
            return middle
        
        if nums[middle] > target:
            return self.recursion(nums, target, start, middle - 1)
        else: 
            return self.recursion(nums, target, middle + 1, end)
        

        

        
        





ss = Solution()

tests = [([4,5,6,7,0,1,2], 0), ([4,5,6,7,0,1,2], 3), ([1], 0)]

for nums, target in tests:
    print(ss.search(nums, target))





    # 4,5,6,7,8,9,0,1,2  target = 5
    # l = 4, m = 8, r = 2
    # l = 4, m =  , r = 8 
    #