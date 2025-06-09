
from typing import List, Optional
import collections

class ListNode:
    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = next

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        hasCycle = {}

        while head:
            if head in hasCycle:
                return True
            hasCycle[head] = 1
            head = head.next
        return False




ss = Solution()





