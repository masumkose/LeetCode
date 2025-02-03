class Solution(object):
    def search(self, nums, target):
        if not nums:
            return False
        
        left, right = 0, len(nums) - 1

        while left <= right:
            mid = (left + right) // 2

            if nums[mid] == target:
                return True
            
            if nums[mid] == nums[left] and nums[mid] == nums[right]:
                left += 1
                right -= 1

            elif nums[left] >= nums[left]:
                if nums[left] <= target < nums[mid]:
                    right = mid - 1
                else:
                    left = mid + 1
    
            else:
                if nums[right] >= target > nums[mid]:
                    left = mid + 1
                else:
                    right = mid - 1

        return False


ss = Solution()


nums = [2,5,6,0,0,1,2]
target = 0
print(ss.search(nums,target))
nums = [2,5,6,0,0,1,2]
target = 3
print(ss.search(nums,target))