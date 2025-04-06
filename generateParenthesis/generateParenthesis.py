
# Given n pairs of parenthesess, write a function to generate all combinations of well-formed parentheses.

from typing import List

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def backtrack(o: int, c: int, curry: str, res: List[str]) -> None:
            if c == 0:
                res.append(curry)
                return
            if o > 0:
                backtrack(o - 1, c, curry + "(", res)
            if c > o:
                backtrack(o, c - 1, curry + ")", res)
            
            
        res = []
        curry = ""
        backtrack(n, n, curry, res)
        return res












ss = Solution()


print(ss.generateParenthesis(3))
print(ss.generateParenthesis(1))
