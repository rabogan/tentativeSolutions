import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;

class Solution {
    public boolean sequenceReconstruction(int[] org, List<List<Integer>> seqs) {
        Map<Integer, Integer> indegrees = new HashMap<>();
        Map<Integer, ArrayList<Integer>> adjList = new HashMap<>();

        for (List<Integer> seq : seqs) {
            if (seq.size() >= 1)
                indegrees.putIfAbsent(seq.get(0), 0);
            for (int i = 1; i < seq.size(); i++) {
                int src = seq.get(i - 1);
                int dest = seq.get(i);
                indegrees.put(dest, indegrees.getOrDefault(dest, 0) + 1);
                ArrayList<Integer> temp = adjList.getOrDefault(src, new ArrayList<Integer>());
                temp.add(dest);
                adjList.put(src, temp);
            }
        }

        if (indegrees.size() != org.length)
            return false;

        Queue<Integer> queue = new LinkedList<>();

        for (Map.Entry<Integer, Integer> entry : indegrees.entrySet()) {
            if (entry.getValue() == 0)
                queue.add(entry.getKey());
        }

        int index = 0;

        while (!queue.isEmpty()) {
            if (queue.size() != 1)
                return false;
            int node = queue.remove();
            if (index >= org.length || org[index++] != node)
                return false;
            for (Integer neighbor : adjList.getOrDefault(node, new ArrayList<Integer>())) {
                indegrees.put(neighbor, indegrees.get(neighbor) - 1);
                if (indegrees.get(neighbor) == 0)
                    queue.add(neighbor);
            }
        }

        return org.length == index;
    }
}
