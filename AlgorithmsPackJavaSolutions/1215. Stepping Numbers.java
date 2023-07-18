import java.util.*;

class Solution {
    private boolean inRange(long low, long high, long num) {
        return low <= num && num <= high;
    }

    private boolean process(Queue<Long> queue, List<Integer> visited, long low, long high, long num) {
        if (num > high)
            return false;

        if (inRange(low, high, num))
            visited.add((int) num);

        queue.add(num);
        return true;
    }

    public List<Integer> countSteppingNumbers(int low, int high) {
        Queue<Long> queue = new LinkedList<>();
        List<Integer> visited = new ArrayList<>();

        if (inRange(low, high, 0))
            visited.add(0);

        for (int i = 1; i <= 9; i++) {
            if (inRange(low, high, i))
                visited.add(i);
            queue.add((long) i);
        }

        while (!queue.isEmpty()) {
            long cur = queue.poll();
            int digit = (int) (cur % 10);

            if (digit != 0 && !process(queue, visited, low, high, cur * 10 + digit - 1))
                break;
            if (digit != 9 && !process(queue, visited, low, high, cur * 10 + digit + 1))
                break;
        }

        return visited;
    }
}
