/*0*/
const long long MOD = 1e9 + 7;
const long long OO = (1e9 + 10) * 200;    // > 200 edge * maxedge-cost

/*1*/
struct Edge {
    int to;
    long long weight;

    Edge(int to, long long weight) :
        to(to), weight(weight) {
    }

    bool operator <(const Edge& e) const {
        return weight > e.weight;
    }
};

/*3*/
int dijkstra(const vector<vector<Edge>>&adjList, int nodes, int source, int target) {
    /*4*/
    vector<long long>dist(nodes, OO);
    dist[source] = 0;

    /*5*/
    vector<long long> pathCount(nodes, 0);
    pathCount[source] = 1;

    /*6*/
    priority_queue<Edge>q;    // small to large
    q.push({source,0});

    while (!q.empty()) {
        /*7*/
        Edge minEdge = q.top();
        int minIndex = minEdge.to;
        q.pop();

        /*8*/
        if (minEdge.weight > dist[minIndex])
            continue;
        // Relax with the outgoing edges of the min node
        for (const auto&Edge : adjList[minIndex]) {
            int to = Edge.to;
            auto weight = Edge.weight;
            /*9*/
            if (dist[to] > dist[minIndex] + weight) {  // New cost. The old SPs are ignored.
                dist[to] = dist[minIndex] + weight;
                pathCount[to] = pathCount[minIndex];
                q.push({ to, dist[to] });
            }
            /*10*/
            else if (dist[to] == dist[minIndex] + weight) {//One more set of paths of equal distance
                pathCount[to] += pathCount[minIndex];
                pathCount[to] %= MOD;
                //DON'T add an edge. It doesn't make new relaxations
            }
        }
    }
    /*11*/
    return pathCount[target];
}

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        /*2a*/
        vector<vector<Edge>>adjList(n);

        for (int i = 0; i < (int)roads.size(); ++i) {
            int from = roads[i][0];
            int to = roads[i][1];
            int cost = roads[i][2];
           
           /*2b*/
            // Undirected edge = 2 directed edges
            adjList[from].push_back({ to, cost });
            adjList[to].push_back({ from, cost });
        }
        return dijkstra(adjList, n, 0, n - 1);
    }
};
/*
0) First, we're using MOD and OO, which set an MOD and 
an arbitrary large value
1) The Edge struct uses *to* and the long long *weight*
2) In the presented Solution function, we create an 
adjacency list from *roads*
2b) We use grab 'from', 'to', and cost and create the 
undirected Edges using these

***WE CALL DIJKSTRA TO FIND THE SP FROM SRC NODE TO 
ALL OTHER NODES, THEN RETURN THE SP FROM SRC TO TARGET***

3) The dijkstra function takes in an adjList, node number, 
source node (0) and target node (n-1)
4) Initialize a vector *dist* using nodes and OO.  This 
represents distance from src to each node in the graph
4b) Set dist[src] to 0, as the distance from src to 
itself is 0
5) Initialize pathCount with (nodes,0). This represents 
the number of SPs from source node to each node in the graph
5b) Set pathCount[source] to 1, as there's 1 path from 
source node to itself
6) Create a pq called q to store unprocessed nodes.  
Push the source node with a weight of 0 to the priority_queue
7) While the q is NOT empty, pop the node of minimum 
weight from it. Set minIndex to .to, and the Edge is minEdge :)
8) If the weight of the minEdge is GREATER THAN the 
currrect shortest distance to minIndex, continue!
8b)  i.e. if(minEdge.weight > dist[minIndex])
9) For each outgoing Edge of minIndex, check if the new
distance to target node 
via that edge is less than the current shortest distance.
9b) If so, update dist[to] and pathCount[to] respectively; 
then push the node on the priority_queue
10) If new distance to target node is equal to the current 
shortest distance, update pathCount[to]
to reflect the new set of paths of equal distance
11) Once all nodes are processed, return pathCount[target].  
This represents all SPs from source to target
*/
