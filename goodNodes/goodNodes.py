
from typing import Optional, List
import collections

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        res = 0

        def dfs(root, m):
            if not root:
                return
            if root.val >= m:
                res += 1
            dfs(root.right, max(root.val, m))
            dfs(root.left, max(root.val, m))

        dfs(root)
        return res



ss = Solution()



