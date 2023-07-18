class Solution:
    def middleNode(self, head):
        tortoise = head
        hare = head

        while hare and hare.next:
            tortoise = tortoise.next
            hare = hare.next.next

        return tortoise
