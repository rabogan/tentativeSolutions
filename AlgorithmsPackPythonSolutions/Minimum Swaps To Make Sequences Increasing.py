class Solution:
    def minSwap(self, nums1: List[int], nums2: List[int]) -> int:
        MAX = 100000 + 1
        memory = [[0, 0] for _ in range(MAX)]
        A = nums1
        B = nums2
        OO = int(1e9)

        memory[0][0] = 0
        memory[0][1] = 1

        for idx in range(1, len(A)):
            memory[idx][0] = OO
            memory[idx][1] = OO

            for LPS in range(2):
                lastA = A[idx - 1]
                lastB = B[idx - 1]
                if LPS:
                    lastA, lastB = lastB, lastA

                if lastA < A[idx] and lastB < B[idx]:
                    memory[idx][0] = min(memory[idx][0], memory[idx - 1][LPS])

                if lastA < B[idx] and lastB < A[idx]:
                    memory[idx][1] = min(memory[idx][1], 1 + memory[idx - 1][LPS])

        return min(memory[len(A) - 1][0], memory[len(A) - 1][1])
