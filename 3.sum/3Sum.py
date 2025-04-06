import collections

class Solution:
    def threeSum(self, nums):
        nums.sort()
        res = []

        for n, a in enumerate(nums):
            if n > 0 and (a == nums[n - 1]):
                continue
            l, r = n + 1, len(nums) - 1
            while (l < r):
                summ = nums[l] + nums[r] + a
                if (summ == 0):
                    res.append([a, nums[l], nums[r]])
                    l = l + 1
                    while nums[l] == nums[l - 1] and l < r:
                        l += 1
                elif (summ  > 0):
                    r = r - 1
                elif (summ < 0):
                    l = l + 1

        return res
                



ss = Solution()

print(ss.threeSum([-1,0,1,2,-1,-4]))