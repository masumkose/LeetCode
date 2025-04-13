
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
    def reorderList(self, head: Optional[ListNode]) -> None:
        nodes = []
        temp = head
        while temp:
            nodes.append(temp)
            temp = temp.next
        i, j = 0, len(nodes) - 1
        while i < j:
            nodes[i].next = nodes[j]
            i += 1
            if i >= j:
                break
            nodes[j].next = nodes[i]
            j -= 1
        nodes[i].next = None



ss = Solution()





