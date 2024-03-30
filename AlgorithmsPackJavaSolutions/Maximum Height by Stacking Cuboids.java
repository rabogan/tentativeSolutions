class Solution {
    private int[][] memory;
    private int[][] cuboidsg;

    public int maxHeight(int[][] cuboids) {
        int MAX_N = 100 + 1;
        memory = new int[MAX_N][MAX_N];
        cuboidsg = cuboids;

        for (int[] row : memory) {
            Arrays.fill(row, -1);
        }

        for (int[] cuboid : cuboids) {
            Arrays.sort(cuboid);
        }

        Arrays.sort(cuboids, (a, b) -> {
            if (a[0] != b[0]) {
                return Integer.compare(a[0], b[0]);
            } else if (a[1] != b[1]) {
                return Integer.compare(a[1], b[1]);
            } else {
                return Integer.compare(a[2], b[2]);
            }
        });

        return stack(0, cuboidsg.length);
    }

    private boolean lessEq(int i, int j) {
        return cuboidsg[i][1] <= cuboidsg[j][1] && cuboidsg[i][2] <= cuboidsg[j][2];
    }

    private int stack(int cur, int prev) {
        if (cur == cuboidsg.length) {
            return 0;
        }

        if (memory[cur][prev] != -1) {
            return memory[cur][prev];
        }

        int choice1 = stack(cur + 1, prev);
        int choice2 = 0;

        if (prev == cuboidsg.length || lessEq(prev, cur)) {
            choice2 = cuboidsg[cur][2] + stack(cur + 1, cur);
        }

        memory[cur][prev] = Math.max(choice1, choice2);
        return memory[cur][prev];
    }
}
