

from typing import List
import collections

class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:

        stack = []
        max_area = 0

        for i, h in enumerate(heights):
            start = i
            while stack and stack[-1][1] > h:
                ind, ind_heigt = stack.pop()
                max_area = max(max_area, ind_heigt * (i - ind))
                print(f"index heigt = {ind_heigt}, len of the rectangle = {i - ind}")
                start = ind
            
            stack.append([start, h])
        
        while stack:
            ind, ind_heigt = stack.pop()
            max_area = max(max_area, ind_heigt * (len(heights) - ind))
            print(f"index heigt = {ind_heigt}, len of the rectangle = {(len(heights) - ind)}")

        return max_area


    def largestRectangleArea_slow_solution(self, heights: List[int]) -> int:

        area_max = 0
        for i in range(len(heights)):
            smallest = heights[i]
            for j in range(i, len(heights)):
                smallest = min(heights[j], smallest)
                area_max = max(area_max, smallest * (j - i + 1))
        return area_max


ss = Solution()


heights = [[2,1,5,6,2,3], [2,4], [2,1,2], [3,6,5,7,4,8,1,0]]

for h in heights:
    print(ss.largestRectangleArea(h))