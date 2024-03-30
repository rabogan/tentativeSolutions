class Solution {
    typedef vector<vector<int>>GRAPH;
    
    void add_edge(GRAPH&graph, int from, int to){
        graph[from].push_back(to);
    }
public:
    bool topSort(GRAPH&graph, vector<bool>&visited){
        int nodes = graph.size();
        vector<int>indegree(nodes,0);
        for(int i = 0; i < nodes; i++){
            for(int j:graph[i])
                indegree[j]++;
        }
        
        queue<int>ready;
        for(int i = 0; i < nodes; i++){
            if(indegree[i]==0)
                ready.push(i);
        }
        
        vector<int>result;
        while(!ready.empty()){
            int cur = ready.front();
            ready.pop();
            result.push_back(cur);
            if(visited[cur])
                return false;
            visited[cur] = true;
            for(int node:graph[cur]){
                if(visited[node])
                    return false;
                if(--indegree[node]==0)
                    ready.push(node);
            }
        }
        if(result.size()==indegree.size())
            return true;
        else
            return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(numCourses==0)
            return true;
        
        GRAPH graph(numCourses);
        
        for(auto&p:prerequisites)
            add_edge(graph,p[0],p[1]);
        
        vector<bool>visited(numCourses);
        
        return topSort(graph,visited);
    }
};
/*
KAHN's ALGORITHM SOLUTION:
1) Notice how we're building the graph.   
It's a simple vector<vector<int>>GRAPH!
2) Topological sorting is DEMANDED here.   The prerequisites 
make it obvious.  To facilitate this, we construct a DAG, with 
directed edges
3) I chose to call the Topological Sort with the (constructed)
graph, and a vector<bool>visited array.  I'm not sure if the 
boolean array is necessary, but felt it would help speed things 
up.  if(visited[node]==true), we have a cycle!

PART II
Topological Sorting deserves a section by itself
1) First, get the size of the graph
2) Make a vector of 'indegrees', and calculate the number of 
edges coming 'INTO' each node
2b) The loop is a little convoluted!
3) After that, we need to construct and add to the queue.
Where we have '0' in-degree nodes, we will push them in the 
queue (or priority queue, if we want lexicographical sorting)
4) We'll iterate through 'popped' elements, pushing them into
a results vector.  Of course, if we've 'met' them along the way, 
we don't have a DAG!
5) However, if our 'current' element (popped from the queue) 
passes the sniff test, then we need to cleverly look at the 
neighbouring/following node.  We want to a) SUBTRACT one 
from the 'indegree' vector element represented by that node.
AT THE SAME TIME, we want to push that node into the queue 
if the indegree[node] value drops to 0!  i.e.
if(--indegree[node]==0)  q.push(node);
6)  The last check (after the queue is empty) is to see 
whether the result.size() == graph.size().  If NOT, then 
we have cycles - a disaster!  If so, then we should be fine :)
*/
