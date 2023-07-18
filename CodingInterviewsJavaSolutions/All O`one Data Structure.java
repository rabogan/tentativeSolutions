https://leetcode.com/problems/all-oone-data-structure/solutions/91416/java-ac-all-strict-o1-not-average-o1-easy-to-read/
class AllOne:
    def __init__(self):
        self.buckets = []
        self.hash = {}
        
    def inc(self, key: str) -> None:
        if key not in self.hash:
            if not self.buckets or self.buckets[-1][0] != 1:
                newBucket = [1, {key}]
                self.buckets.append(newBucket)
                self.hash[key] = newBucket
            else:
                newBucket = self.buckets[-1]
                newBucket[1].add(key)
                self.hash[key] = newBucket
        else:
            curBucket = self.hash[key]
            prevBucket = self.buckets[self.buckets.index(curBucket)-1] if self.buckets.index(curBucket) > 0 else None
            if not prevBucket or prevBucket[0] != curBucket[0]+1:
                newBucket = [curBucket[0]+1, {key}]
                self.buckets.insert(self.buckets.index(curBucket), newBucket)
                self.hash[key] = newBucket
            else:
                prevBucket[1].add(key)
                self.hash[key] = prevBucket
            curBucket[1].remove(key)
            if not curBucket[1]:
                self.buckets.remove(curBucket)
                del self.hash[key]
        
    def dec(self, key: str) -> None:
        if key not in self.hash:
            return
        curBucket = self.hash[key]
        if curBucket[0] == 1:
            curBucket[1].remove(key)
            if not curBucket[1]:
                self.buckets.remove(curBucket)
                del self.hash[key]
        else:
            nextBucket = self.buckets[self.buckets.index(curBucket)+1] if self.buckets.index(curBucket) < len(self.buckets)-1 else None
            if not nextBucket or nextBucket[0] != curBucket[0]-1:
                newBucket = [curBucket[0]-1, {key}]
                self.buckets.insert(self.buckets.index(curBucket)+1, newBucket)
                self.hash[key] = newBucket
            else:
                nextBucket[1].add(key)
                self.hash[key] = nextBucket
            curBucket[1].remove(key)
            if not curBucket[1]:
                self.buckets.remove(curBucket)
                del self.hash[key]
        
    def getMaxKey(self) -> str:
        return '' if not self.buckets else next(iter(self.buckets[-1][1]))
        
    def getMinKey(self) -> str:
        return '' if not self.buckets else next(iter(self.buckets[0][1]))
