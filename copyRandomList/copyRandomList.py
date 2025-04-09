
from typing import List, Optional
import collections


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Node:
    def __init__(self, x :int, next: 'Node' = None, random: 'Node'= None):
        self.val = int(x)
        self.next = next
        self.random = random


class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head:
            return None
        oldToCopy = {}

        cur = head
        while cur:
            copy = Node(cur.val)
            oldToCopy[cur] = copy
            cur = cur.next
        
        cur = head
        while cur:
            copy = oldToCopy[cur]
            copy.next = oldToCopy.get(cur.next)
            copy.random = oldToCopy.get(cur.random)
            cur = cur.next

        return oldToCopy[head]


def print_list(head):
    while head:
        if head.random:
            print(f" curr value = {head.val}, random value = {head.random.val}")
        else:
            print(f" curr value = {head.val}")
        head = head.next



# Create nodes
node0 = Node(7)
node1 = Node(13)
node2 = Node(11)
node3 = Node(10)
node4 = Node(1)

# Set next pointers
node0.next = node1
node1.next = node2
node2.next = node3
node3.next = node4

# Set random pointers
node0.random = None
node1.random = node0
node2.random = node4
node3.random = node2
node4.random = node0

# Head of the linked list
head = node0

ss = Solution()

print_list(head)
print_list(ss.copyRandomList(head))





