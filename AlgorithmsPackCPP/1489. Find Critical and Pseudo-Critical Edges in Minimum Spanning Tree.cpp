/*
This code is finding the critical and pseudo-critical edges of an undirected weighted graph with n nodes.
Critical edges are edges that must be included in every minimum spanning tree (MST) of the graph,
whereas pseudo-critical edges are edges that are not necessarily critical, but are part of some MSTs.

To find these edges, the code first converts the input edges from a vector of vectors to a vector of Edge objects and sorts them by weight. 
It then computes the weight of the optimal MST using Kruskal's algorithm.

Next, it iterates through the sorted edges and considers each edge e in turn. 
It tries adding e to the MST and computes the resulting MST weight. If the resulting MST weight is greater than the optimal MST weight, e is not a crossing edge and should be skipped. 
If the resulting MST weight is the same as the optimal MST weight, e is a pseudo-critical edge and should be added to pseudo_critical. 
Otherwise, e is a critical edge and should be added to critical.

Finally, the function returns a vector of two vectors: critical and pseudo_critical. These vectors contain the indices of the critical and pseudo-critical edges, respectively, in the original input edge vector.

Let's first modify our Kruskal algorithm to support 2 nice features: 
1. Ignoring edges: If there are some edges that we want our MST to ignore, we can simply ignore them. 
2. Forcing edges to be added: If we have some edges that must be in the final MST, even if they are not optimal, we can force them to be added first to the Union-Find data structure, and then run Kruskal's algorithm as usual. 
Now let's identify the critical and pseudo-critical edges. See code comments below. Note: This problem can also be solved using Prim's algorithm.

*/

class UnionFind{
    private:
    int forests{};
    vector<int>rank,parent;
    void link(int x, int y){
        if(rank[x] > rank[y])
            swap(x,y);
        parent[x] = y;
        if(rank[x]==rank[y])
            rank[y]++;
    }
    public:
    UnionFind(int n){
        forests = n;
        rank = vector<int>(n);
        parent = vector<int>(n);

        for(int i = 0; i < n; i++){
            rank[i] = 1;
            parent[i] = i;
        }
    }

    int find_set(int x){
        if(parent[x]==x)
            return x;
        return parent[x] = find_set(parent[x]);
    }

    int union_set(int x, int y){
        x= find_set(x);
        y = find_set(y);
        if(x!=y){
            link(x,y);
            --forests;
        }
        return x!=y;
    }
};

struct Edge{
    int from, to, weight, index;
    Edge(int from, int to, int weight, int index):from(from),to(to),weight(weight),index(index){
    }
    bool operator<(const Edge&e)const{
        return weight < e.weight;
    }
};


/*
This is a function that computes the weight of a minimum spanning tree (MST) of a graph using Kruskal's algorithm. The input is a vector of edges represented as Edge objects, the number of vertices in the graph, a vector of edges to add to the MST (if any), and a set of edges to ignore (if any).
The function starts by creating a UnionFind object, which keeps track of which vertices are connected. It then initializes the MST cost to zero.
Next, it processes the edges to add to the MST. For each edge, it checks whether the two vertices it connects are already in the same set. If they are not, it adds the edge to the MST and updates the MST cost.
After adding any required edges, the function processes the remaining edges in the input edgeList. It skips any edges that are in the edgesIgnore set. For each remaining edge, it checks whether the two vertices it connects are already in the same set. If they are not, it adds the edge to the MST and updates the MST cost.
Finally, the function returns the MST cost.
*/
int MST_Kruskal(const vector<Edge>&edgeList, int nodes, const vector<Edge>&edgesAdd, const set<int>&edgesIgnore){
    UnionFind uf(nodes);
    int mstCost = 0;

    for(auto&e:edgesAdd){
        if(uf.union_set(e.from,e.to))
            mstCost+=e.weight;
    }

    for(auto&e:edgeList){
        if(!edgesIgnore.count(e.index) && uf.union_set(e.from,e.to))
            mstCost+=e.weight;
    }
    return mstCost;
}

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<int>pseudoCritical, critical;
        vector<Edge>edgeList;

        for(int i = 0; i < edges.size(); i++)
            edgeList.push_back({edges[i][0],edges[i][1],edges[i][2],i});

        sort(edgeList.begin(),edgeList.end());

        int mstCost1 = MST_Kruskal(edgeList,n,{},{});

        for(auto&e:edgeList){
            int mstCost2 = MST_Kruskal(edgeList,n,{e},{});
            if(mstCost2>mstCost1)
                continue;
            
            int mstCost3 = MST_Kruskal(edgeList,n,{},{e.index});
            if(mstCost3==mstCost1)
                pseudoCritical.push_back(e.index);
            else
                critical.push_back(e.index);
        }
        return{critical,pseudoCritical};
    }
};