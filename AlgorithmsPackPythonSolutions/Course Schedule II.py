class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        graph = [[] for _ in range(numCourses)]
        incomingEdges = [0] * numCourses

        for prerequisite in prerequisites:
            fromCourse, toCourse = prerequisite
            graph[toCourse].append(fromCourse)
            incomingEdges[fromCourse] += 1

        queue = deque()
        for i in range(numCourses):
            if incomingEdges[i] == 0:
                queue.append(i)

        nodesFound = 0
        result = []
        while queue:
            course = queue.popleft()
            nodesFound += 1
            result.append(course)

            for neighbor in graph[course]:
                incomingEdges[neighbor] -= 1
                if incomingEdges[neighbor] == 0:
                    queue.append(neighbor)

        if nodesFound != numCourses:
            result.clear()
        
        return result
