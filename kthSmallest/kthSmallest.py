
from typing import Optional, List
import collections

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        val = [0]

        def dfs(root, i):
            if not root:
                return
            if i == k:
                val[0] = root.val
                return
            elif i > k:
                return
            dfs(root.left, i + 1)
            dfs(root.right, i + 1)

        dfs(root, 0)
        return val[0]
            


        



ss = Solution()



