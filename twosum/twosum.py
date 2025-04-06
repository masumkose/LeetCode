class Solution:
    def twoSum(self, nums, target):
        l, r = 0, len(nums) - 1

        while (l < r):

            if (nums[l] + nums[r] == target):
                return [l + 1,r + 1]
            elif nums[l] + nums[r] > target:
                r -= 1
            elif nums[l] + nums[r] < target:
                l += 1
                








    def twoSum_first(self, nums, target):
        for i in range(0, len(nums)):
            for j in range(i + 1, len(nums)):
                if nums[i] + nums[j] == target:
                    return [i,j]

    def betterTwosum(self, nums, target):
        my_dic = {}

        for i, num in enumerate(nums):
            diff = target - num
            if diff in my_dic:
                return [my_dic[diff], i]
            my_dic[num] = i





ss = Solution()

nums = [[2,7,11,15], [2,3,4], [-1,0]]
target = [9,6,-1]

for num, tar in zip(nums,target):
    print(ss.twoSum(num, tar))
    # print(ss.betterTwosum(num, tar))