class Solution {
    public int minSwap(int[] nums1, int[] nums2) {
        int MAX = 100000 + 1;
        int[][] memory = new int[MAX][2];
        int[] A = nums1;
        int[] B = nums2;
        int OO = (int) 1e9;

        memory[0][0] = 0;
        memory[0][1] = 1;

        for (int idx = 1; idx < A.length; idx++) {
            memory[idx][0] = OO;
            memory[idx][1] = OO;

            for (int LPS = 0; LPS < 2; LPS++) {
                int lastA = A[idx - 1];
                int lastB = B[idx - 1];
                if (LPS == 1) {
                    int temp = lastA;
                    lastA = lastB;
                    lastB = temp;
                }

                if (lastA < A[idx] && lastB < B[idx]) {
                    memory[idx][0] = Math.min(memory[idx][0], memory[idx - 1][LPS]);
                }

                if (lastA < B[idx] && lastB < A[idx]) {
                    memory[idx][1] = Math.min(memory[idx][1], 1 + memory[idx - 1][LPS]);
                }
            }
        }

        return Math.min(memory[A.length - 1][0], memory[A.length - 1][1]);
    }
}
