class Solution {
    private int[] dr = {-1, 0, 1, 0};
    private int[] dc = {0, 1, 0, -1};

    private class Node {
        int r;
        int c;

        Node(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }

    private boolean isValid(int r, int c, int[][] matrix) {
        if (r < 0 || r >= matrix.length)
            return false;
        if (c < 0 || c >= matrix[0].length)
            return false;
        return true;
    }

    private Pair<List<Node>, Integer> biggerNeighboursAndEdges(int r, int c, int[][] matrix) {
        List<Node> edges = new ArrayList<>();
        int incomingEdges = 0;

        for (int d = 0; d < 4; d++) {
            int nr = dr[d] + r;
            int nc = dc[d] + c;
            if (!isValid(nr, nc, matrix))
                continue;

            if (matrix[r][c] < matrix[nr][nc])
                edges.add(new Node(nr, nc));
            else if (matrix[r][c] > matrix[nr][nc])
                incomingEdges++;
        }

        return new Pair<>(edges, incomingEdges);
    }

    public int longestIncreasingPath(int[][] matrix) {
        int rows = matrix.length;
        int cols = matrix[0].length;
        int[][] incomingEdges = new int[rows][cols];
        Queue<Node> queue = new LinkedList<>();

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                Pair<List<Node>, Integer> result = biggerNeighboursAndEdges(r, c, matrix);
                incomingEdges[r][c] = result.getValue();
                if (incomingEdges[r][c] == 0)
                    queue.add(new Node(r, c));
            }
        }

        int levels = 0;
        while (!queue.isEmpty()) {
            int levelSize = queue.size();
            while (levelSize-- > 0) {
                Node node = queue.poll();
                List<Node> biggerNeighbours = biggerNeighboursAndEdges(node.r, node.c, matrix).getKey();

                for (Node neighbour : biggerNeighbours) {
                    if (--incomingEdges[neighbour.r][neighbour.c] == 0)
                        queue.add(neighbour);
                }
            }
            levels++;
        }

        return levels;
    }
}
