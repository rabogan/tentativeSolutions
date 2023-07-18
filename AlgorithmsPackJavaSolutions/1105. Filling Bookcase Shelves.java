class Solution {
    private int[] memory;

    public int minHeightShelves(int[][] books, int shelfWidth) {
        int MAX = 1000 + 1;
        memory = new int[MAX];
        Arrays.fill(memory, -1);

        return arrange(0, books, shelfWidth);
    }

    private int arrange(int index, int[][] books, int shelfWidth) {
        if (index >= books.length) {
            return 0;
        }

        if (memory[index] != -1) {
            return memory[index];
        }

        int result = Integer.MAX_VALUE;
        int width = 0;
        int maxHeight = 0;

        for (int split = index; split < books.length; split++) {
            width += books[split][0];
            maxHeight = Math.max(maxHeight, books[split][1]);
            if (width > shelfWidth) {
                break;
            }
            result = Math.min(result, maxHeight + arrange(split + 1, books, shelfWidth));
        }

        memory[index] = result;
        return result;
    }
}
