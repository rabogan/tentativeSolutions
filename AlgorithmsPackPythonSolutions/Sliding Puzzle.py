class Solution:
    def slidingPuzzle(self, board: List[List[int]]) -> int:
        goal = "123450"
        directions = [[1, 3], [0, 2, 4], [1, 5], [0, 4], [1, 3, 5], [2, 4]]
        start = ""
        
        for i in range(len(board)):
            for j in range(len(board[0])):
                start += str(board[i][j])
        
        if start == goal:
            return 0
        
        visited = set()
        q = deque()
        q.append(start)
        visited.add(start)
        
        level = 0
        while q:
            size = len(q)
            for _ in range(size):
                cur = q.popleft()
                idx1 = cur.index('0')
                
                for idx2 in directions[idx1]:
                    cur = list(cur)
                    cur[idx1], cur[idx2] = cur[idx2], cur[idx1]
                    cur_str = "".join(cur)
                    
                    if cur_str == goal:
                        return level + 1
                    
                    if cur_str not in visited:
                        visited.add(cur_str)
                        q.append(cur_str)
                    
                    cur[idx1], cur[idx2] = cur[idx2], cur[idx1] 
                    
            level += 1
        
        return -1
