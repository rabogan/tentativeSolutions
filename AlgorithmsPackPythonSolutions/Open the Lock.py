class Solution:
    def prev(self, ch):
        if ch == '0':
            return '9'
        return chr(ord(ch) - 1)
    
    def next(self, ch):
        if ch == '9':
            return '0'
        return chr(ord(ch) + 1)
    
    def openLock(self, deadends: List[str], target: str) -> int:
        start = "0000"
        if start == target:
            return 0
        
        q = collections.deque()
        visited = set(deadends)
        if start in visited:
            return -1
        
        q.append(start)
        visited.add(start)
        
        level = 0
        while q:
            sz = len(q)
            for _ in range(sz):
                cur = q.popleft()
                for d in range(4):
                    cur_list = list(cur)
                    cur_list[d] = self.prev(cur_list[d])
                    cur_prev = "".join(cur_list)
                    if cur_prev == target:
                        return level + 1
                    if cur_prev not in visited:
                        q.append(cur_prev)
                        visited.add(cur_prev)
                    
                    cur_list[d] = self.next(self.next(cur_list[d]))
                    cur_next = "".join(cur_list)
                    if cur_next == target:
                        return level + 1
                    if cur_next not in visited:
                        q.append(cur_next)
                        visited.add(cur_next)
                    
                    cur_list[d] = self.prev(cur_list[d])
                
            level += 1
        
        return -1
