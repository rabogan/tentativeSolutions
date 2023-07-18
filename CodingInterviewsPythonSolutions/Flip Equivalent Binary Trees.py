class Solution:
    def toStr(self, n):
        return str(n)
    
    def parenthesize_canonical(self, root):
        if not root:
            return "()"
        
        left = self.parenthesize_canonical(root.left)
        right = self.parenthesize_canonical(root.right)
        
        if left > right:
            left, right = right, left
        
        return "(" + self.toStr(root.val) + left + right + ")"
    
    def flipEquiv(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        return self.parenthesize_canonical(root1) == self.parenthesize_canonical(root2)
