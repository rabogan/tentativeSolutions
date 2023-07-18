class Solution:
    def transection(self, node):
        tortoise = node
        hare = node
        while hare and hare.next:
            tortoise = tortoise.next
            hare = hare.next.next
            if tortoise == hare:
                return tortoise
        return None

    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return head

        trans = self.transection(head)
        if not trans:
            return trans

        while trans != head:
            head = head.next
            trans = trans.next
        return trans
