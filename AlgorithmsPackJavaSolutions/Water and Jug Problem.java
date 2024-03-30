class Solution {
    public boolean canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        Set<List<Integer>> visited = new HashSet<>();
        Queue<List<Integer>> q = new LinkedList<>();

        if (process(q, visited, 0, 0, targetCapacity))
            return true;

        while (!q.isEmpty()) {
            List<Integer> state = q.poll();
            int jug1 = state.get(0);
            int jug2 = state.get(1);

            int p1 = Math.min(jug1, jug2Capacity - jug2);
            int p2 = Math.min(jug1Capacity - jug1, jug2);

            if (process(q, visited, jug1, 0, targetCapacity) ||
                process(q, visited, 0, jug2, targetCapacity) ||
                process(q, visited, jug1Capacity, jug2, targetCapacity) ||
                process(q, visited, jug1, jug2Capacity, targetCapacity) ||
                process(q, visited, jug1 - p1, jug2 + p1, targetCapacity) ||
                process(q, visited, jug1 + p2, jug2 - p2, targetCapacity)) {
                return true;
            }
        }

        return false;
    }

    private boolean process(Queue<List<Integer>> q, Set<List<Integer>> visited, int jug1, int jug2, int target) {
        if (jug1 + jug2 == target) {
            return true;
        }

        if (jug1 > jug2) {
            int temp = jug1;
            jug1 = jug2;
            jug2 = temp;
        }

        List<Integer> state = Arrays.asList(jug1, jug2);
        if (visited.add(state)) {
            q.offer(state);
        }
        
        return false;
    }
}
