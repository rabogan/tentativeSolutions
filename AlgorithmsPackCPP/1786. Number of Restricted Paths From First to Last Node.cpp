/*
PRE-PROBLEM SETTING UP
1) Firstly, I've defined the Edge (as shown), with operator overloading to help the priority_queue
2) The other constants are used to 
a) Use a MOD to return an answer
b) Avoid overflow
c) Define a MAX_N (20001), and allow us to count the number of unrestricted paths from source to target node using DP

COUNT UNRESTRICTED PATHS (ASSUMING ALL CALLED FUNCTIONS ARE GOOD!)
The solution best starts by using the original function, and building an adjList of Edges
3b) Don't forget to use -1 (roads labeled from 1 to n)
4) We then get the vector<long long>dist by calling dijkstra.  dist, calculated using Dijkstra's algorithm, is a vector showing the SHORTEST DISTANCE from node N to every other node in the graph
5) We will apply DP to count the number of restricted paths from node 0 to node n-1 (1 to N).  This is done by first memsetting that memory to -1, then calling countPaths(0,n-1,adjList,dist);
Notice, we using 0 (for 1), n-1 (for n), the adjList we build, plus dist, the vector showing SHORTEST DISTANCE from node N to every other node in the graph.  The restricted path must have a situation where distanceToLastNode(zi) > distanceToLastNode(zi+1), with 0<=i<=k-1

THE DIJKSTRA FUNCTION
This is long, but shouldn't be too difficult for anyone who has 'done' Dijkstra before!
6) We are, however, returning a vector<long long>dist, which avoids any issues with overflow!
7) We create a PQ of Edges, adding {source,0} to it
8) We repeatedly look for the minimum Edge weight, then use the index of this to iterate through our adjList
9) Dijkstra eventually returns a SHORTEST DISTANCE from node N to every other node in the graph
10) Return the dist

COUNT PATHS:
11) The base case is acheived when source and target node are the SAME!!!
That is, source==target.  If so, a valid path is found, and we return 1
12)  Otherwise, first check the number of paths from our node to destination node using the value in memory.  If it's been computed, return that value!
13)  If it HASN'T been computed, set ret to 0, then loop through all edges from the current node (source).  For each Edge, we check if it leads to a node  Edge.to that is closer to the last node than the current node.  If so, we call count_paths on Edge.to.  We add the value returned by countPaths to ret%MOD
14)  We store ret in memory, so we can reuse it if needed, and return ret!
*/

const long long MOD = 1e9 + 7;
const long long OO = 2000000000 + 10;
const int MAX_N = 2 * 1e4 + 1;
long long memory[MAX_N];

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

vector<long long>dijkstra(const vector<vector<Edge>>&adjList, int n, int source) {
	vector<long long> dist(n, OO);
	vector<bool> vis(n, 0);
	dist[source] = 0;

	priority_queue<Edge>q;	// small to large
	q.push({source,0});

	while (!q.empty()) {
		Edge minEdge = q.top();
		int minIndex = minEdge.to;
		q.pop();

		if (vis[minIndex])
			continue;

		for (const auto& edge : adjList[minIndex]) {
			int to = edge.to;
			int weight = edge.weight;

			if (dist[to] > dist[minIndex] + weight) {
				dist[to] = dist[minIndex] + weight;
				q.push({ to, dist[to] });
			}
		}
		vis[minIndex] = true;
	}
	return dist;
}

// Count paths from src to target. The if condition guarantee a DAG
long long countPaths(int source, int target, vector<vector<Edge>>&adjList, vector<long long>& dist) {
	if (source == target)
		return 1;

	auto& ret = memory[source];
	if (ret != -1)
		return ret;

	ret = 0;
	for (const auto& edge : adjList[source]) {
		if (dist[source] > dist[edge.to]) {
			ret += countPaths(edge.to, target, adjList, dist);
			ret %= MOD;
		}
	}
	return ret;
}

class Solution {
public:
	int countRestrictedPaths(int n, vector<vector<int>>&roads) {
		vector<vector<Edge>>adjList(n);

		for (int i = 0; i < (int)roads.size(); ++i) {
			int from = roads[i][0] - 1;
			int to = roads[i][1] - 1;
			int cost = roads[i][2];
			adjList[from].push_back({ to, cost });
			adjList[to].push_back({ from, cost });
		}
		// Problem defines dist based on source = N
		vector<long long> dist = dijkstra(adjList, n, n - 1);

		memset(memory, -1, sizeof(memory));
		// Problem asks for number decreasing paths from 1 to N
		return countPaths(0, n - 1, adjList, dist);
	}
};