/*
After basic analysis, this is just connected components counting!

The function first checks if the number of connections is less than n-1, which is the minimum number of edges required to connect all nodes. If this condition is not satisfied, it means that there are disconnected components in the graph, and the function proceeds to create a Union-Find data structure uf with n nodes.
The function then iterates through each connection in connections and calls the union_set method of uf to join the nodes represented by the current connection. The union_set method first finds the sets to which the nodes belong using the find_set method of uf and then merges the smaller set into the larger set using the link method of uf. If the sets were merged, it decrements the forests counter of uf by 1.
Finally, the function returns the number of connected components in the graph, which is equal to the number of forests in uf minus 1.
*/

class UnionFind {
private:
    vector<int> rank,parent;
    void link(int x, int y) {
        if (rank[x] > rank[y])
            swap(x, y);    // force x to be smaller

        parent[x] = y;
        if (rank[x] == rank[y])    // equal case
            rank[y]++;
    }
public:
    int forests { 0 };

    UnionFind(int n) {
        rank = vector<int>(n), parent = vector<int>(n);
        forests = n;    // Number of the current forests

        for (int i = 0; i < n; ++i)
            parent[i] = i, rank[i] = 1;
    }

    int find_set(int x) {
        if (x == parent[x])
            return x;
        // This is the path compression
        // the top parent is returned and we re-link
        return parent[x] = find_set(parent[x]);
    }

    bool union_sets(int x, int y) {
        x = find_set(x), y = find_set(y);
        if (x != y) {    // Different components
            link(x, y);
            forests--;    // 2 merged into 1
        }
        return x != y;
    }
};

class Solution {
public:
     int makeConnected(int n, vector<vector<int>>& connections) {
        if((int)connections.size() < n-1)
            // we must have n-1 edges for a tree
            return -1;

        // assume the graph is 3 connected components
        // then we need 3-1 edges to link them (we have enough edges)
        UnionFind uf(n);

        for (auto &edge : connections)
            uf.union_sets(edge[0], edge[1]);

        return uf.forests - 1;
    }
};
