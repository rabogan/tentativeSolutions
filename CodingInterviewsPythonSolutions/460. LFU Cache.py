class LFUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.minFreq = 0
        self.keyValue = {}
        self.keyFreq = {}
        self.freqKeylist = {}
        self.keyIterator = {}

    def get(self, key: int) -> int:
        if key not in self.keyValue:
            return -1
        self.updateLRU(key)
        return self.keyValue[key]

    def put(self, key: int, value: int) -> None:
        if self.capacity == 0:
            return
        if self.capacity == len(self.keyValue) and key not in self.keyValue:
            self.evict()
        if key in self.keyValue:
            self.updateLRU(key)
            self.keyValue[key] = value
        else:
            self.keyValue[key] = value
            self.keyFreq[key] = 1
            if 1 not in self.freqKeylist:
                self.freqKeylist[1] = []
            self.freqKeylist[1].insert(0, key)
            self.keyIterator[key] = self.freqKeylist[1][0]
            self.minFreq = 1

    def updateLRU(self, key: int) -> None:
        self.freqKeylist[self.keyFreq[key]].remove(self.keyIterator[key])
        self.keyFreq[key] += 1
        freq = self.keyFreq[key]
        if freq not in self.freqKeylist:
            self.freqKeylist[freq] = []
        self.freqKeylist[freq].insert(0, key)
        self.keyIterator[key] = self.freqKeylist[freq][0]
        
        if self.freqKeylist[self.minFreq] == []:
            del self.freqKeylist[self.minFreq]
            self.minFreq += 1

    def evict(self) -> None:
        lfu = self.freqKeylist[self.minFreq][-1]
        self.freqKeylist[self.minFreq].pop()
        del self.keyValue[lfu]
        del self.keyFreq[lfu]
        del self.keyIterator[lfu]
