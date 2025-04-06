

def print_list(head):
    current = head
    while current:
        print(current.val, end=" -> ")
        current = current.next
    print("None")

class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution(object):
    def deleteDuplicates(self, head):
        if not head or not head.next:
            return head
        current = head

        while current and current.next:
            if current.val == current.next.val:
                current.next = current.next.next
            else:
                current = current.next
        return head

        

ss = Solution()
node1 = ListNode(1)
node2 = ListNode(1)
node3 = ListNode(2)


node1.next = node2
node2.next = node3

head = node1

print_list(head)
ss.deleteDuplicates(head)
print_list(head)
print("--------------------------------")

node1 = ListNode(1)
node2 = ListNode(1)
node3 = ListNode(2)
node4 = ListNode(3)
node5 = ListNode(3)

node1.next = node2
node2.next = node3
node3.next = node4
node4.next = node5

head = node1

print_list(head)
ss.deleteDuplicates(head)
print_list(head)