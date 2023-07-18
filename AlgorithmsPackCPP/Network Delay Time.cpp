class Solution {
    struct Edge{
        int to;
        int weight;

        Edge(int to, int weight):to(to),weight(weight){
        }

        bool operator < (const Edge&e)const{
            return weight > e.weight;
        }
    };
    const int OO = 1e9;
public:
    vector<int>dijkstra(vector<vector<Edge>>&adjList, int nodes, int src){
        vector<int>dist(nodes,OO);
        dist[src] = 0;
        vector<bool>visited(nodes);
        priority_queue<Edge>q;
        q.push({src,0});

        while(!q.empty()){
            Edge minEdge = q.top();
            q.pop();
            int minIndex = minEdge.to;
            if(visited[minIndex])
                continue;
            
            for(const auto&Edge:adjList[minIndex]){
                int to = Edge.to;
                int weight = Edge.weight;
                if(dist[to] > dist[minIndex]+weight){
                    dist[to] = dist[minIndex]+weight;
                    q.push({to,dist[to]});
                }
            }
            visited[minIndex] = true;
        }
        return dist;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<Edge>>edgeList(n);
        for(auto&t:times)
            edgeList[t[0]-1].push_back({t[1]-1,t[2]});
        
        vector<int>res = dijkstra(edgeList,n,k-1);
        int result = *max_element(res.begin(),res.end());
        if(result>=OO)
            return -1;
        return result;
    }
};
