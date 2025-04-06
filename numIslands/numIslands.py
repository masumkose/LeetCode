
from typing import List

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        
        visited = set()
        rows = len(grid)
        cols = len(grid[0])
        numIslands = 0

        def bfs(r, c):
            que = []
            visited.add((r,c))
            que.append((r,c))
            directions = [(1,0), (-1,0), (0, 1), (0, -1)]

            while que:
                row, col = que.pop()
                for dr, dc in directions:
                    r, c = row + dr, col + dc
                    if  (r in range(rows) and
                        c in range(cols) and
                        (r, c) not in visited and
                        grid[r][c] == '1'):
                        que.append((r,c))
                        visited.add((r,c))



        for c in range(cols):
            for r in range(rows):
                if grid[r][c] == "1" and (r, c) not in visited:
                    bfs(r, c)
                    numIslands += 1

        return numIslands













ss = Solution()

grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","1"],
  ["0","0","0","1","0"]
]


print(ss.numIslands(grid))