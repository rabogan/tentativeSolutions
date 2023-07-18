class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        copy_A = headA
        copy_B = headB
        
        while copy_A != copy_B:
            if copy_A is None:
                copy_A = headB
            else:
                copy_A = copy_A.next
            
            if copy_B is None:
                copy_B = headA
            else:
                copy_B = copy_B.next
        
        return copy_A
