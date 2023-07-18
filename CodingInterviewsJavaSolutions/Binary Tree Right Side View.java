class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if (root == null)
            return result;
        
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        
        while (!queue.isEmpty()) {
            int size = queue.size();
            
            for (int i = 0; i < size; i++) {
                TreeNode cur = queue.poll();
                
                if (i == size - 1)
                    result.add(cur.val);
                
                if (cur.left != null)
                    queue.offer(cur.left);
                
                if (cur.right != null)
                    queue.offer(cur.right);
            }
        }
        
        return result;
    }
}
