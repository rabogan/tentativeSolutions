class Solution:
    def length(self, head):
        count = 0
        while head:
            count += 1
            head = head.next
        return count

    def getNth(self, head, n):
        count = 0
        cur = head
        while cur:
            count += 1
            if count == n:
                return cur
            cur = cur.next
        return None

    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        len = self.length(head)
        head = ListNode(-1, head)

        prev = self.getNth(head, len - n + 1)
        toRemove = prev.next

        prev.next = prev.next.next
        del toRemove

        toRemove = head
        head = head.next

        del toRemove
        return head
