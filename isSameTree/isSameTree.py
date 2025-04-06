
from typing import List, Optional
import collections

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:

        if not p and not q:
            return True
        elif not p or not q:
            return False
        if p.val != q.val:
            return False

        
        return (self.isSameTree(p.right, q.right) and self.isSameTree(p.left, q.left))




root = TreeNode(1)
root.right = TreeNode(3)
root.left = TreeNode(2)

root1 = TreeNode(1)
root1.right = TreeNode(2)
root1.left = TreeNode(3)

ss = Solution()


print(ss.isSameTree(root, root1))


