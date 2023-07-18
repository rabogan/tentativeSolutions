class Solution {
    public Node insert(Node head, int insertVal) {
        if (head == null) {
            Node new_node = new Node(insertVal);
            new_node.next = new_node;
            return new_node;
        }
        
        Node cur = head;
        while (true) {
            int first = cur.val;
            int second = cur.next.val;
            
            if (first <= insertVal && insertVal <= second) {
                break;
            }
            
            if (first > second) {
                if (first <= insertVal || insertVal <= second) {
                    break;
                }
            }
            
            cur = cur.next;
            if (cur == head) {
                break;
            }
        }
        
        Node new_node = new Node(insertVal, cur.next);
        cur.next = new_node;
        return head;
    }
}
