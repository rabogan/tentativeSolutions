class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        maxSum = float('-inf')

        def inorder(node):
            nonlocal maxSum
            if not node:
                return 0

            left = inorder(node.left)
            right = inorder(node.right)

            maxSum = max(node.val, maxSum)
            maxSum = max(maxSum, node.val + left + right)
            maxSum = max(maxSum, node.val + max(left, right))

            return max(node.val, node.val + max(left, right))

        inorder(root)
        return maxSum

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
