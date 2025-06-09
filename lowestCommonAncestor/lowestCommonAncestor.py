<<<<<<< HEAD

from typing import List, Optional
import collections

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        ...






ss = Solution()
=======
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        curr = root

        while curr:
            if curr.val == p.val or curr.val == q.val or (curr.val > q.val and curr.val < p.val):
                return curr.val
            if curr.val > p.val and curr.val > q.val:
                curr = curr.left
            else:
                curr = curr.right


ss = Solution()


>>>>>>> f147aaa163e4e3a84ea187c9e05e5f0676a53635


