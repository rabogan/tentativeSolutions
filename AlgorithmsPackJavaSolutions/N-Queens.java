class Solution {
    private void backtrack(int r, int n, boolean[] normDiag, boolean[] antiDiag, boolean[] columns, List<List<String>> solution, String[] cur) {
        if (r == n) {
            solution.add(new ArrayList<>(Arrays.asList(cur.clone())));
            return;
        }

        for (int c = 0; c < n; c++) {
            int x = r + c;
            int y = n - 1 + r - c;

            if (columns[c] || normDiag[y] || antiDiag[x]) {
                continue;
            }

            char[] chars = cur[r].toCharArray();
            chars[c] = 'Q';
            cur[r] = new String(chars);

            columns[c] = normDiag[y] = antiDiag[x] = true;

            backtrack(r + 1, n, normDiag, antiDiag, columns, solution, cur);

            columns[c] = normDiag[y] = antiDiag[x] = false;
            chars = cur[r].toCharArray();
            chars[c] = '.';
            cur[r] = new String(chars);
        }
    }

    public List<List<String>> solveNQueens(int n) {
        boolean[] normDiag = new boolean[2 * n - 1];
        boolean[] antiDiag = new boolean[2 * n - 1];
        boolean[] columns = new boolean[n];
        List<List<String>> solution = new ArrayList<>();
        String[] cur = new String[n];
        Arrays.fill(cur, new String(new char[n]).replace('\0', '.'));
        backtrack(0, n, normDiag, antiDiag, columns, solution, cur);
        return solution;
    }
}
