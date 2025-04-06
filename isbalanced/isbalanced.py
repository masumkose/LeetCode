
from typing import List, Optional
import collections


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        
        self.isBalance = True
        def dfs(root):
            if not root:
                return 0


            left = dfs(root.left)
            right = dfs(root.right)
            if (abs(left - right) > 1):
                self.isBalance = False
                return 0

            return 1 + max(left, right)
        dfs(root)
        return self.isBalance
        


root = TreeNode(3)
root.left = TreeNode(9)
root.right = TreeNode(20)
root.right.left = TreeNode(15)
root.right.right = TreeNode(7)
root.right.right.right = TreeNode(2)


ss = Solution()

print(ss.isBalanced(root))




