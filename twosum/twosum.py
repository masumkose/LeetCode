class Solution:
    def twoSum(self, nums, target):
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

nums = [[2,7,11,15], [3,2,4], [3,3]]
target = [9,6,6]

for num, tar in zip(nums,target):
    print(ss.twoSum(num, tar))
    print(ss.betterTwosum(num, tar))