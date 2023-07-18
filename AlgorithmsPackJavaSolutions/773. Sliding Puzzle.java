class Solution {
    private static final String GOAL = "123450";
    private static final int[][] DIR = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
    
    public int slidingPuzzle(int[][] board) {
        StringBuilder start = new StringBuilder();
        
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                start.append(board[i][j]);
            }
        }
        
        if (start.toString().equals(GOAL))
            return 0;
        
        Set<String> visited = new HashSet<>();
        Queue<String> queue = new LinkedList<>();
        queue.offer(start.toString());
        visited.add(start.toString());
        
        int level = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                String cur = queue.poll();
                int idx1 = cur.indexOf('0');
                
                for (int idx2 : DIR[idx1]) {
                    char[] curArr = cur.toCharArray();
                    swap(curArr, idx1, idx2);
                    String curStr = String.valueOf(curArr);
                    
                    if (curStr.equals(GOAL))
                        return level + 1;
                    
                    if (!visited.contains(curStr)) {
                        visited.add(curStr);
                        queue.offer(curStr);
                    }
                    
                    swap(curArr, idx1, idx2); // Revert the swap
                }
            }
            
            level++;
        }
        
        return -1;
    }
    
    private void swap(char[] arr, int i, int j) {
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
