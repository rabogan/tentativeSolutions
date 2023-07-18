class Solution:
    def addEdge(self, graph, from_node, to):
        graph[from_node].append(to)
        graph[to].append(from_node)

    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        if n == 1:
            return [0]
        
        graph = [[] for _ in range(n)]
        
        for edge in edges:
            self.addEdge(graph, edge[0], edge[1])
        
        leaves = []
        for i in range(n):
            if len(graph[i]) == 1:
                leaves.append(i)
        
        while n > 2:
            new_leaves = []
            n -= len(leaves)
            
            for leaf in leaves:
                neighbor = graph[leaf][0]
                graph[neighbor].remove(leaf)
                
                if len(graph[neighbor]) == 1:
                    new_leaves.append(neighbor)
            
            leaves = new_leaves
        
        return leaves
