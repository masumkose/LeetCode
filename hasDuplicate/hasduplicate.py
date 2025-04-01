class Solution:
    def hasDuplicate(self, nums):
        my_map = {}
        for num in nums:
            if num in my_map:
                return True
            else:
                my_map[num] = 1
        return False




ss = Solution()

nums = [[1,2,3,3],
        [1,2,3,4]]


for num in nums:
    print(ss.hasDuplicate(num))