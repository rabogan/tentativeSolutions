class Solution:
    def canonical(self, s: str) -> List[int]:
        myMap = {}
        canonicalIndex = 0
        result = []
        
        for ch in s:
            if ch not in myMap:
                myMap[ch] = canonicalIndex
                canonicalIndex += 1
            result.append(myMap[ch])
        
        return result
    
    def isIsomorphic(self, s: str, t: str) -> bool:
        return self.canonical(s) == self.canonical(t)
