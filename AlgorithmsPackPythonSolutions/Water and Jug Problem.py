class Solution:
    def canMeasureWater(self, jug1Capacity: int, jug2Capacity: int, targetCapacity: int) -> bool:
        def process(q: deque, visited: set, jug1: int, jug2: int, target: int) -> None:
            nonlocal found
            if jug1 + jug2 == target:
                found = True
                return
            if jug1 > jug2:
                jug1, jug2 = jug2, jug1
            if (jug1, jug2) not in visited:
                visited.add((jug1, jug2))
                q.append([jug1, jug2])

        if jug1Capacity + jug2Capacity < targetCapacity:
            return False

        visited = set()
        q = deque()
        found = False
        process(q, visited, 0, 0, targetCapacity)

        while q and not found:
            jug1, jug2 = q.popleft()
            p1 = min(jug1, jug2Capacity - jug2)
            p2 = min(jug1Capacity - jug1, jug2)

            process(q, visited, jug1, 0, targetCapacity)
            process(q, visited, 0, jug2, targetCapacity)
            process(q, visited, jug1Capacity, jug2, targetCapacity)
            process(q, visited, jug1, jug2Capacity, targetCapacity)
            process(q, visited, jug1 - p1, jug2 + p1, targetCapacity)
            process(q, visited, jug1 + p2, jug2 - p2, targetCapacity)

        return found
