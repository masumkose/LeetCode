
from typing import Optional, List
import collections

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return
        phone = {"2" :"abc", "3" : "def", "4" : "ghi", "5" : "jkl", "6" : "mno", "7" : "pqrs", "8" : "tuv", "9" : "wxyz"}

        res = []
        def dfs(i, cur):
            if i == len(digits):
                res.append(cur)
                return

            for j in (phone[digits[i]]):
                dfs(i + 1, cur + j)

        dfs(0, "")
        return res



digits = "23"


ss = Solution()

print(ss.letterCombinations(digits))


