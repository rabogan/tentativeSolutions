class UnionFind{
    private:
    vector<int>rank,parent;

    void link(int x, int y){
        if(rank[x] > rank[y])
            swap(x,y);
        parent[x] = y;
        if(rank[x]==rank[y])
            rank[y]++;
    }

    public:
    int forests;

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
        x = find_set(x);
        y = find_set(y);
        if(x!=y){
            link(x,y);
            --forests;
        }
        return x!=y;
    }
};

class Solution {
public:
    bool isSimilar(string&a,string&b){
        int diff = 0;
        for(int i = 0; i < a.size(); i++){
            if(a[i]!=b[i])
                diff++;
            if(diff>2)
                return false;
        }
        return true;
    }

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        UnionFind uf(n);
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(isSimilar(strs[i],strs[j]))
                    uf.union_set(i,j);
            }
        }
        return uf.forests;
    }
};
