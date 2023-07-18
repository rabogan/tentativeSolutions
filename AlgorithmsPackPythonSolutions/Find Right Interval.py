class Solution:
    def findRightInterval(self, intervals):

        startsToIndices = {}
        for i in range(len(intervals)):
            startsToIndices[intervals[i][0]] = i
            
        result = [-1] * len(intervals)
        for i in range(len(intervals)):
            start = intervals[i][1]
            if start in startsToIndices:
                result[i] = startsToIndices[start]
            else:
                keys = sorted(startsToIndices.keys())
                index = bisect.bisect_right(keys, start)
                if index < len(keys):
                    result[i] = startsToIndices[keys[index]]
        
        return result
