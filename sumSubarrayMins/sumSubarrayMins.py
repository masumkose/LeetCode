
from typing import List, Optional
import collections


class Solution:

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


    def sumSubarrayMins_Neetcode(self, arr: List[int]) -> int:
        MOD = 10 ** 9 + 7
        res = 0
        stack = [] # (index, num)
        for i, n in enumerate(arr):
            while stack and n < stack[-1][1]:
                j, m = stack.pop()
                left = j - stack[-1][0] if stack else j + 1
                right = i - j
                res = (res + (left * right * m)) % MOD
            stack.append((i,n))
        for i in range(len(stack)):
            j, n = stack[i]
            left = j - stack[i - 1][0] if i > 0 else j + 1
            right = len(arr) - j
            res = (res + n * left * right) % MOD
        return res

    def sumSubarrayMins_bruteforce(self, arr: List[int]) -> int:
        total = 0
        MOD = 10 ** 9 + 7
        for i in range(0, len(arr)):
            minimum = float("inf")
            for j in range(i, len(arr)):
                minimum = min(arr[j], minimum)
                total = (total + minimum) % MOD
        return total




ss = Solution()

arr = [3,1,2,4]

print(ss.sumSubarrayMins(arr))



