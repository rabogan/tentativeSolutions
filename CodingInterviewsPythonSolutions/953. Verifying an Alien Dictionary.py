class Solution:
    def isSmaller(self, s1: str, s2: str) -> bool:
        len1 = len(s1)
        len2 = len(s2)
        
        length = min(len1, len2)
        
        for i in range(length):
            if s1[i] != s2[i]:
                return self.myMap[s1[i]] < self.myMap[s2[i]]
        
        return len1 < len2
    
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        self.myMap = {ch: i for i, ch in enumerate(order)}
        
        for i in range(1, len(words)):
            if words[i - 1] != words[i] and not self.isSmaller(words[i - 1], words[i]):
                return False
        
        return True
