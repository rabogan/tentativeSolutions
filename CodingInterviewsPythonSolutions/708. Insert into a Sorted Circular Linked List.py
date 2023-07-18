# Definition for a Node.
class Node:
    def __init__(self, val=None, next=None):
        self.val = val
        self.next = next

class Solution:
    def insert(self, head: 'Optional[Node]', insertVal: int) -> 'Node':
        if not head:
            new_node = Node(insertVal)
            new_node.next = new_node
            return new_node
        
        cur = head
        while True:
            first = cur.val
            second = cur.next.val
            
            if first <= insertVal <= second:
                break
            
            if first > second:
                if first <= insertVal or insertVal <= second:
                    break
            
            cur = cur.next
            if cur == head:
                break
        
        new_node = Node(insertVal, cur.next)
        cur.next = new_node
        return head
