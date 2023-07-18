class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        ptr1 = 0
        ptr2 = 0
        count = 0
        
        while ptr1 < len(s) and ptr2 < len(t):
            if s[ptr1] == t[ptr2]:
                count += 1
                ptr1 += 1
                ptr2 += 1
            else:
                ptr2 += 1
        
        return count == len(s)
