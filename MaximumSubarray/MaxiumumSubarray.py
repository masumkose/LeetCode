
class Solution(object):
    def maxSubArray(self, nums):
        res = nums[0]
        maxEnding = nums[0]


        for i in range(1,len(nums)):
            maxEnding = max(maxEnding + nums[i], nums[i])
            res = max(res, maxEnding)
        return res




nums = [
        [-2,1,-3,4,-1,2,1,-5,4],
        [1],
        [-2,4],
        [5,4,-1,7,8]
]

ss = Solution()


for num in nums:
    print(ss.maxSubArray(num))

