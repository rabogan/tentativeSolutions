from heapq import heappush, heappop

class ListNodeComp:
    def __init__(self, node):
        self.node = node
    
    def __lt__(self, other):
        return self.node.val < other.node.val

class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        minHeap = []
        
        for node in lists:
            if node:
                comp = ListNodeComp(node)
                heappush(minHeap, (comp, node))
        
        head = ListNode()
        tail = head
        
        while minHeap:
            _, cur = heappop(minHeap)
            
            if cur.next:
                comp = ListNodeComp(cur.next)
                heappush(minHeap, (comp, cur.next))
            
            tail.next = cur
            tail = tail.next
        
        return head.next
