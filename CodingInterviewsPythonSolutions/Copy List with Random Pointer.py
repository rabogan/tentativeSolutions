# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head:
            return None

        # Create a mapping of original nodes to their corresponding copies
        node_map = {}
        cur = head
        while cur:
            node_map[cur] = Node(cur.val)
            cur = cur.next

        # Assign next and random pointers for the copy nodes based on the mapping
        cur = head
        while cur:
            copy_node = node_map[cur]
            copy_node.next = node_map.get(cur.next)
            copy_node.random = node_map.get(cur.random)
            cur = cur.next

        return node_map[head]
