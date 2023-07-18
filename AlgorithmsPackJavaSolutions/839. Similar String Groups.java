class Solution {
    private class UnionFind {
        private int[] rank;
        private int[] parent;
        public int forests;

        public UnionFind(int n) {
            forests = n;
            rank = new int[n];
            parent = new int[n];

            for (int i = 0; i < n; i++) {
                rank[i] = 1;
                parent[i] = i;
            }
        }

        private void link(int x, int y) {
            if (rank[x] > rank[y])
                parent[y] = x;
            else {
                parent[x] = y;
                if (rank[x] == rank[y])
                    rank[y]++;
            }
        }

        private int find_set(int x) {
            if (parent[x] == x)
                return x;
            return parent[x] = find_set(parent[x]);
        }

        public boolean union_set(int x, int y) {
            x = find_set(x);
            y = find_set(y);
            if (x != y) {
                link(x, y);
                --forests;
                return true;
            }
            return false;
        }
    }

    public boolean isSimilar(String a, String b) {
        int diff = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) != b.charAt(i))
                diff++;
            if (diff > 2)
                return false;
        }
        return true;
    }

    public int numSimilarGroups(String[] strs) {
        int n = strs.length;
        UnionFind uf = new UnionFind(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isSimilar(strs[i], strs[j]))
                    uf.union_set(i, j);
            }
        }
        return uf.forests;
    }
}
