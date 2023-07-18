class Solution:
    def killProcess(self, pid: List[int], ppid: List[int], kill: int) -> List[int]:
        graph = {}
        for i in range(len(pid)):
            self.add_edge(graph, ppid[i], pid[i])
        
        return self.killer(graph, kill)
    
    def add_edge(self, graph, from_node, to_node):
        if from_node not in graph:
            graph[from_node] = []
        graph[from_node].append(to_node)
    
    def dfs(self, graph, kill, visited):
        visited.add(kill)
        if kill in graph:
            for node in graph[kill]:
                if node not in visited:
                    self.dfs(graph, node, visited)
    
    def killer(self, graph, kill):
        visited = set()
        self.dfs(graph, kill, visited)
        return list(visited)
