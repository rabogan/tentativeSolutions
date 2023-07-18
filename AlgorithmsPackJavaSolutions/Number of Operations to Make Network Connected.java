class Solution {
    private class UnionFind {
        private int[] rank;
        private int[] parent;
        public int forests;

        public UnionFind(int n) {
            rank = new int[n];
            parent = new int[n];
            forests = n;

            for (int i = 0; i < n; ++i) {
                parent[i] = i;
                rank[i] = 1;
            }
        }

        private void link(int x, int y) {
            if (rank[x] > rank[y]) {
                int temp = x;
                x = y;
                y = temp;
            }

            parent[x] = y;
            if (rank[x] == rank[y])
                rank[y]++;
        }

        private int find_set(int x) {
            if (x != parent[x])
                parent[x] = find_set(parent[x]);
            return parent[x];
        }

        public boolean union_sets(int x, int y) {
            x = find_set(x);
            y = find_set(y);
            if (x != y) {
                link(x, y);
                forests--;
            }
            return x != y;
        }
    }

    public int makeConnected(int n, int[][] connections) {
        if (connections.length < n - 1)
            return -1;

        UnionFind uf = new UnionFind(n);
        for (int[] edge : connections)
            uf.union_sets(edge[0], edge[1]);

        return uf.forests - 1;
    }
}
