
from typing import List, Optional
import collections



class Solution:
    def numberOfWays(self, s: str) -> int:
        totalzeros, totalones = s.count("0"), s.count("1")
        totalways = 0
        zeroes = 0
        ones = 0
        for i in range(len(s)):
            if s[i] == '1':
                ones = ones + 1
                totalways += zeroes * (totalzeros - zeroes)
            else:
                zeroes = zeroes + 1
                totalways += ones * (totalones - ones)

        return totalways

    def numberOfWays_recursion(self, s: str) -> int:
        size = len(s)
        def recursion(i, selection, prev):
            if selection == 0:
                return 1
            if i >= size:
                return 0
            
            if s[i] != prev:
                return recursion(i + 1, selection - 1, s[i]) + recursion(i + 1, selection, prev)
            else:
                return recursion(i + 1, selection, prev) 

        return recursion(0, 3, -1)



ss = Solution()
s = "001101"

print(ss.numberOfWays(s))




