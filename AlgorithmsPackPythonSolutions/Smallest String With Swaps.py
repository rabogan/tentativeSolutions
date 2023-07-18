class Solution:
    def smallestStringWithSwaps(self, s: str, pairs: List[List[int]]) -> str:
        graph = [[] for _ in range(len(s))]
        
        def add_edge(graph, from_node, to_node):
            graph[from_node].append(to_node)
            graph[to_node].append(from_node)
        
        def dfs(graph, node, visited, cc_nodes):
            visited[node] = True
            cc_nodes.append(node)
            
            for neighbour in graph[node]:
                if not visited[neighbour]:
                    dfs(graph, neighbour, visited, cc_nodes)
        
        for pair in pairs:
            add_edge(graph, pair[0], pair[1])
        
        visited = [False] * len(s)
        
        for i in range(len(s)):
            if not visited[i]:
                cc_nodes = []
                dfs(graph, i, visited, cc_nodes)
                
                cc_letters = [s[node] for node in cc_nodes]
                cc_letters.sort()
                cc_nodes.sort()
                
                for j in range(len(cc_nodes)):
                    s = s[:cc_nodes[j]] + cc_letters[j] + s[cc_nodes[j]+1:]
        
        return s
