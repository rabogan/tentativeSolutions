class Solution:
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        pos = [0] * len(words)
        matchingWords = 0
        charToIndices = {}
        for i in range(len(words)):
            charToIndices.setdefault(words[i][0], []).append(i)
        
        for ch1 in s:
            wordIndices = charToIndices.get(ch1, [])
            charToIndices[ch1] = []
            
            for idx in wordIndices:
                word = words[idx]
                pos[idx] += 1
                
                if pos[idx] == len(word):
                    matchingWords += 1
                else:
                    ch2 = word[pos[idx]]
                    charToIndices.setdefault(ch2, []).append(idx)
        
        return matchingWords
