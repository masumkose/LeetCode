
from typing import List, Optional
import collections


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        if not preorder or not inorder:
            return None
        
        root = TreeNode(preorder[0])
        mid = inorder.index(preorder[0])
        root.left = self.buildTree(preorder[1:mid + 1], inorder[:mid])
        root.right = self.buildTree(preorder[mid + 1:], inorder[mid + 1:])
        return root



ss = Solution()
preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]


def print_tree(root: Optional[TreeNode]) -> None:
    if not root:
        return
    print(root.val)
    print_tree(root.left)
    print_tree(root.right)

print_tree(ss.buildTree(preorder, inorder))





