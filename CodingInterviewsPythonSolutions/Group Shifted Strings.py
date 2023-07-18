class Solution:
    def canonical(self, s: str) -> str:
        t = ''
        diff = ord(s[0]) - ord('a')
        for i in range(len(s)):
            t += chr(ord('a') + (ord(s[i]) - ord('a') - diff + 26) % 26)
        return t
    
    def groupStrings(self, strings: List[str]) -> List[List[str]]:
        myMap = {}
        for s in strings:
            myMap.setdefault(self.canonical(s), []).append(s)
        return list(myMap.values())
