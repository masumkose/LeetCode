
from typing import Optional, List
import collections

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        

        def dfs(root, minimum, maximum):
            if not root:
                return True
            
            if minimum <= root.val <= maximum:
                return dfs(root.left, minimum, root.val) and dfs(root.right, root.val, maximum)
            return False


        return dfs(root, float("-inf"), float("+inf"))




ss = Solution()



