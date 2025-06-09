
from typing import List
import collections



class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:  # "dvdf"  
        l = 0                                   # l = 0, r = 0
        visited = set()                                 # maxS = 0
        maxS = 0

        for r in range(len(s)):
            while s[r] in visited:
                visited.remove(s[l])
                l += 1
            
            visited.add(s[r])
            maxS = max(maxS, r - l + 1)
        

        return maxS



    
ss = Solution()
test_cases = ["abcabcbb", "bbbbb", "pwwkew", "dvdf"]

for st in test_cases:
    print(ss.lengthOfLongestSubstring(st))


    




