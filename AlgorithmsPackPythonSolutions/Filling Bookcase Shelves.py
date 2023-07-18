class Solution:
    def minHeightShelves(self, books: List[List[int]], shelfWidth: int) -> int:
        MAX = 1000 + 1
        memory = [-1] * MAX

        def arrange(index):
            if index >= len(books):
                return 0

            if memory[index] != -1:
                return memory[index]

            result = float('inf')
            width = 0
            max_height = 0

            for split in range(index, len(books)):
                width += books[split][0]
                max_height = max(max_height, books[split][1])
                if width > shelfWidth:
                    break
                result = min(result, max_height + arrange(split + 1))

            memory[index] = result
            return result

        return arrange(0)
