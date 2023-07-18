class Solution:
    def toStr(self, n):
        return str(n)
    
    def parenthesize(self, root):
        if not root:
            return "()"
        
        left = self.parenthesize(root.left)
        right = self.parenthesize(root.right)
        
        return "(" + self.toStr(root.val) + left + right + ")"
    
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        big = self.parenthesize(root)
        small = self.parenthesize(subRoot)
        return small in big
