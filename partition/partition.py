
from typing import List, Optional
import collections


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isPalindrome(self, s: str, i: int, j: int) -> bool:
        while i < j:
            if s[i] != s[j]:
                return False
            i, j = i + 1, j - 1
        return True
    

    def partition(self, s: str) -> List[List[str]]:
        
        res = []
        cur = []

        def dfs(i):
            if i >= len(s):
                res.append(cur.copy())
                return
            
            for j in range(i, len(s)):
                if self.isPalindrome(s, i, j):
                    cur.append(s[i:j+1])
                    dfs(j + 1)
                    cur.pop()
        dfs(0)
        return res




s = "aab"
ss = Solution()

print(ss.partition(s))




