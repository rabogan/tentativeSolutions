class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        maxDiameter = 0
        
        def height(root):
            nonlocal maxDiameter
            if not root:
                return 0
            
            leftHeight = height(root.left)
            rightHeight = height(root.right)
            
            maxDiameter = max(maxDiameter, leftHeight + rightHeight)
            
            return 1 + max(leftHeight, rightHeight)
        
        if not root:
            return 0
        
        height(root)
        return maxDiameter
