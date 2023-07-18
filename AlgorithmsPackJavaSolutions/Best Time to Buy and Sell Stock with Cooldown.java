class Solution {
    private int[][][] memory;
    private int[] prices;

    public int maxProfit(int[] prices) {
        int MAX = 5000 + 1;
        memory = new int[MAX][2][3];
        this.prices = prices;

        for (int[][] matrix : memory) {
            for (int[] row : matrix) {
                Arrays.fill(row, -1);
            }
        }

        return profit(0, 0, 0);
    }

    private int profit(int index, int hasStock, int lastTrans) {
        if (index >= prices.length) {
            return 0;
        }

        if (memory[index][hasStock][lastTrans] != -1) {
            return memory[index][hasStock][lastTrans];
        }

        int doNothing = profit(index + 1, hasStock, 0);
        int buy = 0;
        int sell = 0;

        if (hasStock == 1) {
            sell = prices[index] + profit(index + 1, 0, 1);
        } else if (lastTrans != 1) {
            buy = -prices[index] + profit(index + 1, 1, 2);
        }

        memory[index][hasStock][lastTrans] = Math.max(doNothing, Math.max(buy, sell));
        return memory[index][hasStock][lastTrans];
    }
}
