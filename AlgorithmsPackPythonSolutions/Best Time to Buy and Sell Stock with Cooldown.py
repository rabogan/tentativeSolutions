class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        MAX = 5000 + 1
        memory = [[[-1] * 3 for _ in range(2)] for _ in range(MAX)]
        prices_ = prices

        NOTHING, SELL, BUY = 0, 1, 2

        def profit(index, hasStock, lastTrans):
            if index >= len(prices_):
                return 0

            if memory[index][hasStock][lastTrans] != -1:
                return memory[index][hasStock][lastTrans]

            doNothing = profit(index + 1, hasStock, NOTHING)
            buy = 0
            sell = 0

            if hasStock:
                sell = prices_[index] + profit(index + 1, 0, SELL)
            elif lastTrans != SELL:
                buy = -prices_[index] + profit(index + 1, 1, BUY)

            memory[index][hasStock][lastTrans] = max(doNothing, buy, sell)
            return memory[index][hasStock][lastTrans]

        return profit(0, 0, NOTHING)
