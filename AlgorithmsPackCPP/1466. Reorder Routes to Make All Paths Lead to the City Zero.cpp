class Solution {
    struct Edge{
        int to;   //This shows where the edge is going TO
        bool built;    //This bool indicates whether or not a 'directed' edge exists or not!
        //We will be counting Edge.built, incrementing reorient_count (see below) with it
    };
    
    typedef vector<vector<Edge>>GRAPH;
    
    void add_undirected_edge(GRAPH&graph, int from, int to){
        graph[from].push_back({to,true});  //Push_back the 'to' and 'true' if an edge exists!
        graph[to].push_back({from,false});  //Push_back 'from' and 'false' if an edge doesn't exist (BUT, allowing a connection!!!)
    }
    
    void dfs(GRAPH& graph, int node, vector<bool>&visited, int &reorient_count){  //Note the number of & here!
        visited[node] = true;
        
        for(Edge&e:graph[node])  //We start from 0...and will end up merely counting the number of roads we want to flip!
            //All roads lead to R0ME, right?  So, if 0->1's edge is TRUE, we will want to FLIP it (therefore, adding to)
            //the reorient_count!
            if(!visited[e.to]){
                reorient_count+=e.built;
                dfs(graph,e.to,visited,reorient_count);
            }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int reorient_count = 0;  //Ultimately, this will count the number of edges that need to be reversed
        
        GRAPH graph(n);   //Our graph will involve a vector of vector of Edges (see Edge struct!)
        vector<bool>visited(n);  //This is needed for the dfs call
        
        for(auto &edge:connections){  //This is rudimentary, and builds our graph.  Don't forget the '&'!!!
            add_undirected_edge(graph,edge[0],edge[1]);
        }
        
        dfs(graph,0,visited,reorient_count);   
        //We're using reorient_count by reference.  The dfs function will return a completed count
        
        return reorient_count;
    }
};