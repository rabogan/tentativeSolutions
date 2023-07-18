class Solution:
    def lowestCommonAncestor(self, p: 'Node', q: 'Node') -> 'Node':
        copy_p = p
        copy_q = q
        
        while copy_p != copy_q:
            copy_p = copy_p.parent
            if not copy_p:
                copy_p = q
            
            copy_q = copy_q.parent
            if not copy_q:
                copy_q = p
        
        return copy_p