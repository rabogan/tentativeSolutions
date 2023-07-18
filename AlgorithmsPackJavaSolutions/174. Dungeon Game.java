class Solution {
    private static final int MAX = 200 + 1;
    private int[][] memory;
    private int[][] dungeon;
    private static final int OO = (int) 1e9;

    public int calculateMinimumHP(int[][] dungeon) {
        memory = new int[MAX][MAX];
        this.dungeon = dungeon;

        for (int[] row : memory) {
            Arrays.fill(row, -1);
        }

        return minHealth(0, 0);
    }

    private int minHealth(int r, int c) {
        int rows = dungeon.length;
        int cols = dungeon[0].length;

        if (r >= rows || c >= cols) {
            return OO;
        }

        if (r == rows - 1 && c == cols - 1) {
            if (dungeon[r][c] < 0) {
                return 1 - dungeon[r][c];
            }
            return 1;
        }

        if (memory[r][c] != -1) {
            return memory[r][c];
        }

        int health = Math.min(minHealth(r + 1, c), minHealth(r, c + 1));

        if (health <= dungeon[r][c]) {
            return 1;
        }

        int ret = health - dungeon[r][c];
        memory[r][c] = ret;
        return ret;
    }
}
