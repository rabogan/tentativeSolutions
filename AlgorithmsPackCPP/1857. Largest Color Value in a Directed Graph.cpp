class Solution {
public:


    typedef vector<vector<int>>GRAPH;

    void addEdge(GRAPH&graph, int from, int to){
        graph[from].push_back(to);
    }

    int topSort(GRAPH&graph, string&colors){
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
        vector<vector<int>>colorValues(nodes,vector<int>(26));
        int nodesFound = 0;
        int result = 0;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            int color = colors[cur]-'a';
            colorValues[cur][color]++;
            nodesFound++;

            result = max(result,colorValues[cur][color]);

            for(int j:graph[cur]){
                if(--incomingEdges[j]==0){
                    q.push(j);
                }
                for(int col = 0; col < 26; col++){
                    colorValues[j][col] = max(colorValues[j][col],colorValues[cur][col]);
                }
            }
        }
        if(nodesFound!=nodes)
            return -1;

        return result;
    }

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        GRAPH graph(colors.size());
        for(auto&e:edges)
            addEdge(graph,e[0],e[1]);

        return topSort(graph,colors);
    }
};