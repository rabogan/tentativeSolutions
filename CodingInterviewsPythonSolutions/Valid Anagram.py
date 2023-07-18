class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        freq1 = {}
        freq2 = {}
        
        for ch in s:
            freq1[ch] = freq1.get(ch, 0) + 1
        
        for ch in t:
            freq2[ch] = freq2.get(ch, 0) + 1
        
        if len(freq1) != len(freq2):
            return False
        
        for ch, freq in freq1.items():
            if freq != freq2.get(ch, 0):
                return False
        
        return True
