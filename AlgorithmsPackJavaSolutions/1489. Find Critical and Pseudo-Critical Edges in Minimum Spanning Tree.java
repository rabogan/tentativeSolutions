class Solution {
    private class UnionFind {
        private int forests;
        private int[] rank;
        private int[] parent;

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
            if (rank[x] > rank[y]) {
                int temp = x;
                x = y;
                y = temp;
            }
            parent[x] = y;
            if (rank[x] == rank[y]) {
                rank[y]++;
            }
        }

        public int findSet(int x) {
            if (parent[x] == x) {
                return x;
            }
            parent[x] = findSet(parent[x]);
            return parent[x];
        }

        public boolean unionSet(int x, int y) {
            x = findSet(x);
            y = findSet(y);
            if (x != y) {
                link(x, y);
                forests--;
            }
            return x != y;
        }
    }

    private class Edge implements Comparable<Edge> {
        private int from;
        private int to;
        private int weight;
        private int index;

        public Edge(int from, int to, int weight, int index) {
            this.from = from;
            this.to = to;
            this.weight = weight;
            this.index = index;
        }

        @Override
        public int compareTo(Edge e) {
            return Integer.compare(weight, e.weight);
        }
    }

    private int mstKruskal(List<Edge> edgeList, int nodes, List<Edge> edgesAdd, Set<Integer> edgesIgnore) {
        UnionFind uf = new UnionFind(nodes);
        int mstCost = 0;

        for (Edge e : edgesAdd) {
            if (uf.unionSet(e.from, e.to)) {
                mstCost += e.weight;
            }
        }

        for (Edge e : edgeList) {
            if (!edgesIgnore.contains(e.index) && uf.unionSet(e.from, e.to)) {
                mstCost += e.weight;
            }
        }
        return mstCost;
    }

    public List<List<Integer>> findCriticalAndPseudoCriticalEdges(int n, int[][] edges) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> critical = new ArrayList<>();
        List<Integer> pseudoCritical = new ArrayList<>();
        List<Edge> edgeList = new ArrayList<>();

        for (int i = 0; i < edges.length; i++) {
            edgeList.add(new Edge(edges[i][0], edges[i][1], edges[i][2], i));
        }

        Collections.sort(edgeList);

        int mstCost1 = mstKruskal(edgeList, n, new ArrayList<>(), new HashSet<>());

        for (Edge e : edgeList) {
            int mstCost2 = mstKruskal(edgeList, n, Collections.singletonList(e), new HashSet<>());
            if (mstCost2 > mstCost1) {
                continue;
            }

            int mstCost3 = mstKruskal(edgeList, n, new ArrayList<>(), Collections.singleton(e.index));
            if (mstCost3 == mstCost1) {
                pseudoCritical.add(e.index);
            } else {
                critical.add(e.index);
            }
        }

        result.add(critical);
        result.add(pseudoCritical);
        return result;
    }
}