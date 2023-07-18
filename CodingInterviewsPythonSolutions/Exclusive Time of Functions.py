from typing import List

class Entry:
    def __init__(self, id: int, time: int):
        self.id = id
        self.startTime = time
        self.subcallTime = 0

class Solution:
    def parse(self, log: str) -> List[int]:
        parts = log.replace(':', ' ').split()
        id = int(parts[0])
        type = True if parts[1] == 'start' else False
        time = int(parts[2])
        
        return [id, int(type), time]
    
    def exclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        result = [0] * n
        logStack = [Entry(0, 0)]
        
        for log in logs:
            id, type, time = self.parse(log)
            
            if type:
                logStack.append(Entry(id, time))
            else:
                e = logStack.pop()
                sTime = e.startTime
                total = time - sTime + 1
                exclusive = total - e.subcallTime
                
                eParent = logStack.pop()
                eParent.subcallTime += total
                logStack.append(eParent)
                
                result[id] += exclusive
        
        return result
