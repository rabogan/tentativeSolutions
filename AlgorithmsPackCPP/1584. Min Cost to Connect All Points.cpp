class UnionFind{
    private:
    int forests{};
    vector<int>rank,parent;
    void link(int x, int y){
        if(rank[x]>rank[y])
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

    bool union_set(int x, int y){
        x = find_set(x);
        y = find_set(y);
        if(x!=y){
            link(x,y);
            --forests;
        }
        return x!=y;
    }
};

struct Edge{
    int from;
    int to;
    int weight;
    Edge(int from, int to, int weight):from(from),to(to),weight(weight){
    }
    bool operator<(const Edge&e)const{
        return weight > e.weight;
    }
};

class Solution {
public:
    int Kruskal(vector<Edge>&edgeList, int n){
        priority_queue<Edge>q;
        for(auto&e:edgeList)
            q.push(e);
        UnionFind uf(n);

        int mstCost = 0;
        while(!q.empty()){
            Edge e = q.top();
            q.pop();
            if(uf.union_set(e.from,e.to))
                mstCost+=e.weight;
        }
        return mstCost;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<Edge>edgeList;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                int cost = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edgeList.push_back({i,j,cost});
            }
        }
        return Kruskal(edgeList,n);
    }
};