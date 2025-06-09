
from typing import List


class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        visited = set()
        rows, cols = len(grid), len(grid[0])

        def bfs(r, c):
            q = []
            visited.add((r,c))
            q.append((r,c))
            directions = [(1,0), (-1,0), (0,1), (0,-1)]
            area = 1

            while q:
                row, col = q.pop()
                for dr, dc in directions:
                    r, c = row + dr, col + dc
                    if  (r in range(rows) and
                        c in range(cols) and
                        (r, c) not in visited and
                        grid[r][c] == 1):
                        visited.add((r,c))
                        q.append((r,c))
                        area += 1
            return area
            
        maxArea = 0


        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 1 and not (r,c) in visited:
                    area = bfs(r,c)
                    maxArea = max(maxArea, area)

        return maxArea



ss = Solution()

grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]

print(ss.maxAreaOfIsland(grid=grid))
