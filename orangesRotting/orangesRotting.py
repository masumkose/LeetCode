
from typing import List, Optional
import collections



class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        time = 0
        stack = []
        ROWS, COLS = len(grid), len(grid[0])
        numOranges = 0

        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c] == 2:
                    stack.append((r,c))
                elif grid[r][c] == 1:
                    numOranges += 1
    
        time = 0
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        while stack and numOranges > 0:
            for i in range(len(stack)):
                r, c = stack.pop(0)
                for dr, dc in directions:
                    row, col = dr + r, dc + c
                    if (0 <= row < ROWS and 0 <= col < COLS and grid[row][col] == 1):
                        stack.append((row, col))
                        grid[row][col] = 2
                        numOranges -= 1
                    

            time += 1
        
        return time if numOranges == 0 else -1



grid = [[0,2]]
ss = Solution()
print(ss.orangesRotting(grid))





