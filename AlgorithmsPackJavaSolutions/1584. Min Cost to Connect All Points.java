import java.util.*;

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

        public int findSet(int x) {
            if (parent[x] == x)
                return x;
            return parent[x] = findSet(parent[x]);
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

        private void link(int x, int y) {
            if (rank[x] > rank[y])
                parent[y] = x;
            else {
                parent[x] = y;
                if (rank[x] == rank[y])
                    rank[y]++;
            }
        }
    }

    private class Edge implements Comparable<Edge> {
        private int from;
        private int to;
        private int weight;

        public Edge(int from, int to, int weight) {
            this.from = from;
            this.to = to;
            this.weight = weight;
        }

        public int compareTo(Edge e) {
            return Integer.compare(weight, e.weight);
        }
    }

    public int minCostConnectPoints(int[][] points) {
        int n = points.length;
        List<Edge> edgeList = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int cost = Math.abs(points[i][0] - points[j][0]) + Math.abs(points[i][1] - points[j][1]);
                edgeList.add(new Edge(i, j, cost));
            }
        }

        return kruskal(edgeList, n);
    }

    private int kruskal(List<Edge> edgeList, int n) {
        Collections.sort(edgeList);
        UnionFind uf = new UnionFind(n);
        int mstCost = 0;

        for (Edge e : edgeList) {
            if (uf.unionSet(e.from, e.to))
                mstCost += e.weight;
        }

        return mstCost;
    }
}
