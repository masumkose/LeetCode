
from typing import List, Optional
import collections

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
            
        if not root:
            return False
        
        if (self.isSame(root, subRoot)):
            return True
        

        return(self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot))



    def isSame(self, root, subRoot):
        if not root and not subRoot:
            return True
        if not root or not subRoot:
            return False
    
        if root.val != subRoot.val:
            return False
        
        return (self.isSame(root.left, subRoot.left) and self.isSame(root.right, subRoot.right))
        




root = TreeNode(1)
root.left = TreeNode(1)
# root.right = TreeNode(5)
# root.left.left = TreeNode(1)
# root.left.right = TreeNode(2)
# root.left.right.left = TreeNode(0)

root1 = TreeNode(1)
# root1.left = TreeNode(1)
# root1.right = TreeNode(2)



ss = Solution()


print(ss.isSubtree(root, root1))

