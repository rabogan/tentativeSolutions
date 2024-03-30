class RandomizedSet:
    def __init__(self):
        self.values = []
        self.value_vectorIndex = {}

    def insert(self, val: int) -> bool:
        if val in self.value_vectorIndex:
            return False

        self.value_vectorIndex[val] = len(self.values)
        self.values.append(val)
        return True

    def remove(self, val: int) -> bool:
        if val not in self.value_vectorIndex:
            return False

        idx = self.value_vectorIndex[val]
        self.values[idx], self.values[-1] = self.values[-1], self.values[idx]
        self.value_vectorIndex[self.values[idx]] = idx
        del self.value_vectorIndex[self.values[-1]]
        self.values.pop()

        return True

    def getRandom(self) -> int:
        return random.choice(self.values)
