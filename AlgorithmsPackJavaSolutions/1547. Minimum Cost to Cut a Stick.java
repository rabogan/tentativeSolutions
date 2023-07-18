class Solution {
    private int[][] memory;

    public int minCost(int n, int[] cuts) {
        int MAX = 100 + 1 + 2;
        memory = new int[MAX][MAX];
        for (int[] row : memory) {
            Arrays.fill(row, -1);
        }

        int[] cutsArray = new int[cuts.length + 2];
        System.arraycopy(cuts, 0, cutsArray, 0, cuts.length);
        cutsArray[cuts.length] = 0;
        cutsArray[cuts.length + 1] = n;
        Arrays.sort(cutsArray);

        return cost(0, cutsArray.length - 1, cutsArray);
    }

    private int cost(int start, int end, int[] cuts) {
        if (start + 1 == end) {
            return 0;
        }

        if (memory[start][end] != -1) {
            return memory[start][end];
        }

        int result = Integer.MAX_VALUE;
        for (int split = start + 1; split < end; split++) {
            int left = cost(start, split, cuts);
            int right = cost(split, end, cuts);
            int diff = cuts[end] - cuts[start];
            int total = left + right + diff;
            result = Math.min(result, total);
        }

        memory[start][end] = result;
        return result;
    }
}
