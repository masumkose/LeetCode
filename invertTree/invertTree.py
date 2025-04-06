# Definition for a binary tree node.
from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return None

        tmp = root.left
        root.left = root.right
        root.right = tmp
        self.invertTree(root.right)
        self.invertTree(root.left)
        return root


root = TreeNode(2)
root.left = TreeNode(1)
root.right = TreeNode(3)


def print_tree(node):
    if node:
        print(node.val, end=' ')
        print_tree(node.left)
        print_tree(node.right)

ss = Solution()

ss.invertTree(root=root)
print_tree(root)


