from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def arrayToTree(arr):
    if not arr or arr[0] is None:  # Edge case: Empty array or first element is null
        return None

    root = TreeNode(arr[0])
    queue = deque([root])
    i = 1  # Start processing from the second element in the array

    while i < len(arr):
        current = queue.popleft()

        # Assign left child
        if i < len(arr) and arr[i] is not None:
            current.left = TreeNode(arr[i])
            queue.append(current.left)
        i += 1

        # Assign right child
        if i < len(arr) and arr[i] is not None:
            current.right = TreeNode(arr[i])
            queue.append(current.right)
        i += 1

    return root  # Return the root of the constructed tree


def preorderTraversal(root):
    if root is None:
        return []
    
    return [root.val] + preorderTraversal(root.left) + preorderTraversal(root.right)



def depthFirstValuesrecorsive(root, i):
    if root is None:
        return []
    leftValues = depthFirstValuesrecorsive(root.left, i + 1)
    rightValues = depthFirstValuesrecorsive(root.right, i + 1)
    return [root.val] + leftValues + rightValues

def depthFirstValues(root):
    if root is None:
        return
    stack = [root]
    arr = []
    while(len(stack) > 0):
        current = stack.pop()
        arr.append(root.val)

        if current.right:
            stack.append(current.right)
        if current.left:
            stack.append(current.left)

    return arr

class Solution(object):
    def minDepth(self, root):
        if root is None:
            return 0
        if root.left is None and root.right is None:
            return 1
        if root.left is None:
            return self.minDepth(root.right) + 1
        if root.right is None:
            return self.minDepth(root.left) + 1
        
        return min(self.minDepth(root.left), self.minDepth(root.right)) + 1

    def hasPathSum(self, root, targetSum):
        if root is None:
            return False
        return (self.hasPathSum_helper(root, targetSum , 0))

    def hasPathSum_helper(self, root, targetSum, sum):
        if root is None:
            return
        if root.left is None and root.right is None:
            return root.val + sum == targetSum
        if root.left is None:
            return self.hasPathSum_helper(root.right, targetSum, sum + root.val)
        if root.right is None:
            return self.hasPathSum_helper(root.left, targetSum, sum + root.val)
        
        return self.hasPathSum_helper(root.left, targetSum, sum + root.val) or self.hasPathSum_helper(root.right, targetSum, sum + root.val)
    
    def pathSum(self, root, targetSum):
        if root is None:
            return []
        sol = []
        self.pathSum_helper(root, targetSum , 0, [], sol)
        return sol

    def pathSum_helper(self, root, targetSum, sum, arr, sol):
        if root is None:
            return

        arr.append(root.val)
        sum += root.val
        if root.left is None and root.right is None:
            if sum == targetSum:
                sol.append(list(arr))
            arr.pop()
            return
        
        self.pathSum_helper(root.right, targetSum, sum, arr, sol)
        self.pathSum_helper(root.left, targetSum, sum, arr, sol)

        arr.pop()

    def flatten(self, root):
        if root is None:
            return None
        stack = [root]
        head = None
        while(len(stack) > 0):
            current = stack.pop()
            if head:
                head.right = current
                head.left = None

            if current.right:
                stack.append(current.right)
            if current.left:
                stack.append(current.left)
            head = current
        

        



ss = Solution()
root = arrayToTree([1,2,5,3,4,None,6])
ss.flatten(root)
print(preorderTraversal(root))

root = arrayToTree([0])
ss.flatten(root)
print(preorderTraversal(root))


