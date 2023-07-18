class Solution {
    private int[] memory;

    public int maxSumAfterPartitioning(int[] arr, int k) {
        int MAX = 500 + 1;
        memory = new int[MAX];
        Arrays.fill(memory, -1);

        return partition(0, arr, k);
    }

    private int partition(int start, int[] arr, int k) {
        if (start == arr.length) {
            return 0;
        }

        if (memory[start] != -1) {
            return memory[start];
        }

        int result = Integer.MIN_VALUE;
        int maxValue = Integer.MIN_VALUE;

        for (int split = start; split < start + k; split++) {
            if (split >= arr.length) {
                break;
            }
            maxValue = Math.max(maxValue, arr[split]);
            int length = split - start + 1;
            result = Math.max(result, length * maxValue + partition(split + 1, arr, k));
        }

        memory[start] = result;
        return result;
    }
}
