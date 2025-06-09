
from typing import List, Optional
import collections



class Solution:
    def subArrayRanges(self, nums: List[int]) -> int:
        mins = self.sumSubarrayMins(nums)
        maxs = self.sumSubarrayMaxs(nums)
        mod = 10 ** 9 + 7
        ans = (maxs - mins + mod) % mod
        return ans

    def sumSubarrayMaxs(self, arr: List[int]) -> int:
        mod = 10 ** 9 + 7
        n = len(arr)
        
        stack = []
        left = [0] * n
        for i in range(n):
            count = 1
            while stack and arr[i] > stack[-1][0]:
                count += stack.pop()[1]
            stack.append((arr[i], count))
            left[i] = count
        
        stack = []
        right = [0] * n
        for i in range(n - 1, -1, -1):
            count = 1
            while stack and arr[i] >= stack[-1][0]:
                count += stack.pop()[1]
            stack.append((arr[i], count))
            right[i] = count
        
        res = 0
        for i in range(n):
            res += arr[i] * left[i] * right[i]
            res %= mod
        return res
    def sumSubarrayMins(self, arr: List[int]) -> int:
        mod = 10 ** 9 + 7
        n = len(arr)
        
        stack = []
        left = [0] * n
        for i in range(n):
            count = 1
            while stack and arr[i] < stack[-1][0]:
                count += stack.pop()[1]
            stack.append((arr[i], count))
            left[i] = count
        
        stack = []
        right = [0] * n
        for i in range(n - 1, -1, -1):
            count = 1
            while stack and arr[i] <= stack[-1][0]:
                count += stack.pop()[1]
            stack.append((arr[i], count))
            right[i] = count
        
        res = 0
        for i in range(n):
            res += arr[i] * left[i] * right[i]
            res %= mod
        return res

    def subArrayRanges_brute_force(self, nums: List[int]) -> int:
        MOD = 10 ** 9 + 7
        res = 0
        for i in range(len(nums)):
            maxi = float("-inf")
            minimum = float("+inf")
            for j in range(i, len(nums)):
                maxi = max(maxi, nums[j])
                minimum = min(minimum, nums[j])
                res = (res + maxi - minimum) % MOD
        return res



ss = Solution()

test_nums = [[1,2,3], [1,3,3], [4,-2,-3,4,1]]

for nums in test_nums:
    print(ss.subArrayRanges(nums))



