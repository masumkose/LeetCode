
from typing import Optional, List
import collections

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        i = 0
        res = root.val

        def dfs(node):
            nonlocal i, res
            if not node:
                return
            
            dfs(node.left)
            i += 1
            if i == k:
                res = node.val
                return
            dfs(node.right)
        dfs(root)
        return res


root = TreeNode(3)
root.left = TreeNode(1)
root.right = TreeNode(4)
root.left.right = TreeNode(2)

ss = Solution()

print(ss.kthSmallest(root, 1))




