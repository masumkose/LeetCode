
from typing import List, Optional
import collections


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def exists(self, board: List[List[str]], word: str)-> bool:
        if not board:
            return False
        if not word:
            return True
        
        memo = set()

        rows, cols = len(board), len(board[0])
    
        def dfs(r, c, i):
            if i == len(word):
                return True
            
            if (min(r,c) < 0 or r >= rows or c >= cols or (r, c) in memo):
                return False
            if board[r][c] != word[i]:
                return False

            directions = [(1,0), (-1,0), (0,1), (0,-1)]

            memo.add((r, c))
            for dr, dc in directions:
                if dfs(r + dr, c + dc, i + 1):
                    return True
                
            memo.remove((r, c))


            return False


        for r in range(rows):
            for c in range(cols):
                if (dfs(r, c, 0) == True):
                    return True
        return False



board, word = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], "SFCS"
board1, word1 = [["a"]], "a"

ss = Solution()


print(ss.exists(board=board, word=word))
print(ss.exists(board=board1, word=word1))




