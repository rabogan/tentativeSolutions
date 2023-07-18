class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        lessThan = ListNode(0)
        remaining = ListNode(0)

        before = lessThan
        after = remaining

        while head:
            if head.val < x:
                before.next = head
                before = head
            else:
                after.next = head
                after = head
            head = head.next

        before.next = remaining.next
        after.next = None
        head = lessThan.next

        return head
