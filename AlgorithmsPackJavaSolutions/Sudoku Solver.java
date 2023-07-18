class Solution {
    private int[][] rows = new int[9][9];
    private int[][] cols = new int[9][9];
    private int[][][] box = new int[3][3][9];
    private List<Integer> emptyRow = new ArrayList<>();
    private List<Integer> emptyCol = new ArrayList<>();

    public void solveSudoku(char[][] board) {
        init();

        // Mark initial reserved values
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] != '.') {
                    int digit = board[r][c] - '1';
                    set(digit, r, c, 1);
                } else {
                    emptyRow.add(r);
                    emptyCol.add(c);
                }
            }
        }

        backtrack(board, 0);
    }

    private void init() {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                rows[r][c] = 0;
                cols[r][c] = 0;
                for (int d = 0; d < 9; d++) {
                    box[r/3][c/3][d] = 0;
                }
            }
        }
        emptyRow.clear();
        emptyCol.clear();
    }

    private boolean backtrack(char[][] board, int idx) {
        if (idx >= emptyRow.size())
            return true;

        int r = emptyRow.get(idx);
        int c = emptyCol.get(idx);

        for (int d = 0; d < 9; d++) {
            if (canPlace(d, r, c)) {
                set(d, r, c, 1);
                board[r][c] = (char) ('1' + d);

                if (backtrack(board, idx + 1))
                    return true;

                set(d, r, c, 0);
                board[r][c] = '.';
            }
        }
        return false;
    }

    private boolean canPlace(int d, int r, int c) {
        return rows[r][d] == 0 && cols[c][d] == 0 && box[r / 3][c / 3][d] == 0;
    }

    private void set(int d, int r, int c, int value) {
        rows[r][d] = value;
        cols[c][d] = value;
        box[r / 3][c / 3][d] = value;
    }
}
