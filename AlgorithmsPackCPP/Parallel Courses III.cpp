class Solution {
    typedef vector<vector<int>>GRAPH;

    void addEdge(GRAPH&graph, int from, int to){
        graph[from].push_back(to);
    }
public:
    vector<int>topSort(GRAPH&graph, vector<int>&time){
        int nodes = graph.size();
        vector<int>incomingEdges(nodes);
        for(int i = 0; i < nodes; i++){
            for(int j:graph[i]){
                incomingEdges[j]++;
            }
        }
        queue<int>q;
        for(int i = 0; i < nodes; i++){
            if(incomingEdges[i]==0){
                q.push(i);
            }
        }
        vector<int>result(nodes);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            result[cur]+=time[cur];

            for(int j:graph[cur]){
                if(--incomingEdges[j]==0){
                    q.push(j);
                }
                result[j] = max(result[j],result[cur]);
            }
        }
        return result;
    }

    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        GRAPH graph(n);
        for(auto&rel:relations)
            addEdge(graph,rel[0]-1,rel[1]-1);

        vector<int>timeComp = topSort(graph,time);
        int res = *max_element(timeComp.begin(),timeComp.end());
        return res;
    }
};
