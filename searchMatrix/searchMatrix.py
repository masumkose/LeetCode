
from typing import List
import collections


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:

        row_l, row_r = 0, len(matrix) - 1
        col_l, col_r = 0, len(matrix[0]) - 1
        row = 0

        while row_l <= row_r:
            mid = row_l + ((row_r - row_l) // 2)
            if matrix[mid][0] <= target <= matrix[mid][col_r]:
                row = mid
                break
            elif target >= matrix[mid][0]:
                row_l = mid + 1
            else:
                row_r = mid - 1
            
        if self.search(matrix[row], target) == -1:
            return False
        else:
            return True

        
    def search(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums) - 1

        while left <= right:
            mid = left + ((right - left) // 2)
            if target == nums[mid]:
                return mid
            elif target < nums[mid]:
                right = mid - 1
            else:
                left = mid + 1
            
        return -1







ss = Solution()



test_matrixes = [   
                    ([[1,3,5,7],[10,11,16,20],[23,30,34,60]], 3), 
                    ([[1,3,5,7],[10,11,16,20],[23,30,34,60]], 13),
                    ([[1,3,5,7],[10,11,16,20],[23,30,34,50]], 11)
                ]


for matrix, target in test_matrixes:
    print(ss.searchMatrix(matrix, target))



