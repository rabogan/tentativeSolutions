class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < numCourses; i++) {
            graph.add(new ArrayList<>());
        }
        
        int[] incomingEdges = new int[numCourses];
        for (int[] prerequisite : prerequisites) {
            int fromCourse = prerequisite[1];
            int toCourse = prerequisite[0];
            graph.get(fromCourse).add(toCourse);
            incomingEdges[toCourse]++;
        }
        
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < numCourses; i++) {
            if (incomingEdges[i] == 0) {
                queue.add(i);
            }
        }
        
        int nodesFound = 0;
        List<Integer> result = new ArrayList<>();
        while (!queue.isEmpty()) {
            int course = queue.poll();
            nodesFound++;
            result.add(course);
            
            for (int neighbor : graph.get(course)) {
                incomingEdges[neighbor]--;
                if (incomingEdges[neighbor] == 0) {
                    queue.add(neighbor);
                }
            }
        }
        
        if (nodesFound != numCourses) {
            result.clear();
        }
        
        int[] order = new int[result.size()];
        for (int i = 0; i < result.size(); i++) {
            order[i] = result.get(i);
        }
        
        return order;
    }
}
