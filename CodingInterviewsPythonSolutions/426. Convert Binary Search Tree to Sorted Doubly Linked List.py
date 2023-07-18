# Definition for a Node.
class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def treeToDoublyList(self, root: 'Optional[Node]') -> 'Optional[Node]':
        def treeToDoublyLinkedTraversal(root):
            if not root:
                return None, None

            left_first, left_last = treeToDoublyLinkedTraversal(root.left)
            right_first, right_last = treeToDoublyLinkedTraversal(root.right)

            first = root
            last = root

            if left_first:
                root.left = left_last
                left_last.right = root
                first = left_first

            if right_first:
                root.right = right_first
                right_first.left = root
                last = right_last

            return first, last

        if not root:
            return None

        first, last = treeToDoublyLinkedTraversal(root)
        first.left = last
        last.right = first

        return first
