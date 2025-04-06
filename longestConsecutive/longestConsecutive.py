
import collections

class Solution:
    def longestConsecutive(self, nums):
        nums_set = set(nums)
        max_l = 0

        for num in nums_set:
            if num - 1 not in nums_set:
                length = 0
                i = num

                while i in nums_set:
                    length += 1
                    i += 1

                max_l = max(length, max_l)
        
        return max_l




    def longestConsecutive_sorting(self, nums):
        if not nums:
            return 0
        nums.sort()

        ml = 0
        l = 1
        for n in range(1, len(nums)):

            if (nums[n] == nums[n - 1] + 1):
                l += 1
            elif nums[n] == nums[n - 1]:
                continue
            else:
                ml = max(ml, l)
                l = 1
        
        ml = max(ml, l)
        return ml





ss = Solution()



# print(ss.longestConsecutive([100,4,200,1,3,2]))
print(ss.longestConsecutive([0,3,7,2,5,8,4,6,0,1]))
