class LRUCache:
    def __init__(self, capacity: int):
        self.size = capacity
        self.lru = []
        self.key_value = {}
        self.key_iterator = {}

    def get(self, key: int) -> int:
        if key not in self.key_value:
            return -1
        self.updateLRU(key)
        return self.key_value[key]

    def put(self, key: int, value: int) -> None:
        if len(self.key_value) == self.size and key not in self.key_value:
            self.evict()
        self.updateLRU(key)
        self.key_value[key] = value

    def updateLRU(self, key: int) -> None:
        if key in self.key_value:
            self.lru.remove(self.key_iterator[key])
        self.lru.insert(0, key)
        self.key_iterator[key] = self.lru[0]

    def evict(self) -> None:
        del self.key_value[self.lru[-1]]
        del self.key_iterator[self.lru[-1]]
        self.lru.pop()
