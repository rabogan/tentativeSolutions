class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        charToIndex = {}
        sz = len(s)
        result = 0
        start = 0
        for end in range(sz):
            if s[end] in charToIndex:
                start = max(start, charToIndex[s[end]] + 1)
            charToIndex[s[end]] = end
            result = max(result, end - start + 1)
        return result
