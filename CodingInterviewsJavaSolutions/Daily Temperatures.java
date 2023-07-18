class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int size = temperatures.length;
        int[] result = new int[size];
        Deque<Integer> stack = new ArrayDeque<>();
        
        for (int i = 0; i < size; i++) {
            while (!stack.isEmpty() && temperatures[i] > temperatures[stack.peekLast()]) {
                int index = stack.removeLast();
                result[index] = i - index;
            }
            stack.addLast(i);
        }
        
        return result;
    }
}
