class Solution:
    def restoreArray(self, adjacentPairs: List[List[int]]) -> List[int]:
        graph = {}
        
        def add_edge(graph, from_node, to_node):
            graph.setdefault(from_node, []).append(to_node)
            graph.setdefault(to_node, []).append(from_node)
        
        def dfs(graph, node, visited, result):
            visited.add(node)
            result.append(node)
            
            for neighbour in graph[node]:
                if neighbour not in visited:
                    dfs(graph, neighbour, visited, result)
        
        for pair in adjacentPairs:
            add_edge(graph, pair[0], pair[1])
        
        visited = set()
        result = []
        
        for node in graph:
            if len(graph[node]) == 1:
                dfs(graph, node, visited, result)
                break
        
        return result
