
from typing import Optional, List
import collections

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:

    def solveNQueens(self, n: int) -> List[List[str]]:
        board = [["."] * n for i in range(n)]
        res = []
        posDiag = set()
        negDiag = set()
        col = set()

        def dfs(r):
            if not self.isValid(board):
                return
            if (r == n):
                copy = ["".join(row) for row in board]
                res.append(copy)
                return
            
            for c in range(n):
                if c in col or (c + r) in posDiag or (r - c) in negDiag:
                    continue
                col.add(c)
                posDiag.add(r + c)
                negDiag.add(r - c)
                board[r][c] = "Q"
                dfs(r + 1)
                board[r][c] = '.'
                col.remove(c)
                posDiag.remove(r + c)
                negDiag.remove(r - c)

            


        dfs(0)
        return res












ss = Solution()
print(ss.solveNQueens(4))


