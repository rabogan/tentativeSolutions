class Solution:
    def eliminateMaximum(self, dist: List[int], speed: List[int]) -> int:
        sz = len(dist)
        arrivalTime = [(d + s - 1) // s for d, s in zip(dist, speed)]
        arrivalTime.sort()
        
        monster = 0
        for i in range(len(arrivalTime)):
            if i >= arrivalTime[monster]:
                break
            monster += 1
        
        return monster
