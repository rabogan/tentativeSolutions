class Solution:
    def recoverTree(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        mn = None
        mx = None
        predecessor = None

        def select(cur, pred):
            nonlocal mn, mx
            if not mx:
                mn = cur
                mx = pred
            else:
                mn = cur

        def traverse(node):
            nonlocal predecessor
            if not node:
                return

            traverse(node.left)
            if predecessor and node.val < predecessor.val:
                select(node, predecessor)
            predecessor = node
            traverse(node.right)

        traverse(root)
        mn.val, mx.val = mx.val, mn.val

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
