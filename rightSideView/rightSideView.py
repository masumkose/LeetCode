
from typing import Optional, List
import collections

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        q = []
        q.append(root)
        while q:
            qlen = len(q)
            val = float("inf")
            for _ in range(qlen):
                node = q.pop(0)
                if node:
                    val = node.val
                    q.append(node.left)
                    q.append(node.right)
            if val != float("inf"):
                res.append(val)
        return res


root = TreeNode(1)
root.right = TreeNode(2)
root.left = TreeNode(3)
root.left.left = TreeNode(4)
root.left.right = TreeNode(5)
root.left.left.left = TreeNode(6)

ss = Solution()


print(ss.rightSideView(root))


