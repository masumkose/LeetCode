# Definition for a binary tree node.
from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:

    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        return max (self.maxDepth(root.left) + 1, self.maxDepth(root.right) + 1)


root = TreeNode(3)
root.left = TreeNode(9)
root.right = TreeNode(20)
root.right.left = TreeNode(15)
root.right.right = TreeNode(7)



def print_tree(node):
    if node:
        print(node.val, end=' ')
        print_tree(node.left)
        print_tree(node.right)

ss = Solution()

print(ss.maxDepth(root=root))
