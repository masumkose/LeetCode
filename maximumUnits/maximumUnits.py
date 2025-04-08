
from typing import List, Optional
import collections


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        sorted_box = sorted(boxTypes, key=lambda x: x[1], reverse=True)
        total = 0
        for box, unit in sorted_box[::-1]:
            if truckSize - box > 0:
                total += box * unit
                truckSize -= box
            elif truckSize > 0:
                total += truckSize * unit
                break
            else:
                break
        return total




boxTypes = [[1,3],[5,5],[2,5],[4,2],[4,1],[3,1],[2,2],[1,3],[2,5],[3,2]]

truckSize = 35

ss = Solution()

print(ss.maximumUnits(boxTypes, truckSize))




