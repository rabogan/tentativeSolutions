class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        if not root:
            return result
        
        queue = deque()
        queue.append(root)
        
        while queue:
            size = len(queue)
            
            for i in range(size):
                cur = queue.popleft()
                
                if i == size - 1:
                    result.append(cur.val)
                
                if cur.left:
                    queue.append(cur.left)
                
                if cur.right:
                    queue.append(cur.right)
        
        return result
