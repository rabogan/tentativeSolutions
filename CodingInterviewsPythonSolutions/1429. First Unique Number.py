from collections import OrderedDict

class FirstUnique:

    def __init__(self, nums: List[int]):
        self.uniqueNumbers = []
        self.valueToNode = OrderedDict()
        for num in nums:
            self.add(num)

    def showFirstUnique(self) -> int:
        if self.uniqueNumbers:
            return self.uniqueNumbers[0]
        return -1

    def add(self, value: int) -> None:
        if value in self.valueToNode:
            if self.valueToNode[value] is not None:
                self.uniqueNumbers.remove(self.valueToNode[value])
                self.valueToNode[value] = None
        else:
            self.uniqueNumbers.append(value)
            self.valueToNode[value] = value
