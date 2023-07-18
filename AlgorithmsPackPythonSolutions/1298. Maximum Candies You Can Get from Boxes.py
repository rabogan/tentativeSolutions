class Solution:
    def maxCandies(self, status: List[int], candies: List[int], keys: List[List[int]], containedBoxes: List[List[int]], initialBoxes: List[int]) -> int:
        collected = 0
        
        def addKeysFromBoxes(status, keys, boxes):
            for box in boxes:
                for key in keys[box]:
                    status[key] = 1
        
        def openBoxes(q, visited, status, candies, boxes):
            for box in boxes:
                if not visited[box] and status[box]:
                    q.append(box)
                    visited[box] = True
                    nonlocal collected
                    collected += candies[box]
        
        q = deque()
        visited = [False] * len(status)
        
        addKeysFromBoxes(status, keys, initialBoxes)
        openBoxes(q, visited, status, candies, initialBoxes)
        
        while q:
            box = q.popleft()
            addKeysFromBoxes(status, keys, containedBoxes[box])
            openBoxes(q, visited, status, candies, containedBoxes[box])
        
        return collected
